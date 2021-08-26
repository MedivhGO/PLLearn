//�̳߳ز��Դ���
#include <muduo/base/ThreadPool.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/base/CurrentThread.h>

#include <boost/bind.hpp>
#include <stdio.h>

void print()
{//�򵥵ش�ӡtid
	printf("tid=%d\n", muduo::CurrentThread::tid());
}

void printString(const std::string& str)
{
	printf("tid=%d, str=%s\n", muduo::CurrentThread::tid(), str.c_str());
}

int main()
{//����һ���̳߳�
	muduo::ThreadPool pool("MainThreadPool");
	//5���̵߳��̳߳�
	pool.start(5);
	//�����2����������print
	pool.run(print);
	pool.run(print);
	//�����100������
	for (int i = 0; i < 100; ++i)
	{
		char buf[32];
		snprintf(buf, sizeof buf, "task %d", i);
		//�󶨵ĺ����Ǵ�������
		pool.run(boost::bind(printString, std::string(buf)));
	}
	//����CountDownLatch���󣬼���ֵcount =1��ֻ��ִ��һ��countDown
	muduo::CountDownLatch latch(1);
	//���һ������
	pool.run(boost::bind(&muduo::CountDownLatch::countDown, &latch));
	//count��Ϊ0��ʱ��һֱ�ȴ�
	latch.wait();
	//�ر��̳߳�
	pool.stop();
}