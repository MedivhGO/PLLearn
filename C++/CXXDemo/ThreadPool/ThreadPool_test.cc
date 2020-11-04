//线程池测试代码
#include <muduo/base/ThreadPool.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/CurrentThread.h>

#include <boost/bind.hpp>
#include <stdio.h>

void print()
{//简单地打印tid
	printf("tid=%d\n", muduo::CurrentThread::tid());
}

void printString(const std::string& str)
{
	printf("tid=%d, str=%s\n", muduo::CurrentThread::tid(), str.c_str());
}

int main()
{//创建一个线程池
	muduo::ThreadPool pool("MainThreadPool");
	//5个线程的线程池
	pool.start(5);
	//添加了2个任务运行print
	pool.run(print);
	pool.run(print);
	//添加了100个任务
	for (int i = 0; i < 100; ++i)
	{
		char buf[32];
		snprintf(buf, sizeof buf, "task %d", i);
		//绑定的函数是带参数的
		pool.run(boost::bind(printString, std::string(buf)));
	}
	//创建CountDownLatch对象，计数值count =1，只需执行一个countDown
	muduo::CountDownLatch latch(1);
	//添加一个任务
	pool.run(boost::bind(&muduo::CountDownLatch::countDown, &latch));
	//count不为0的时候一直等待
	latch.wait();
	//关闭线程池
	pool.stop();
}