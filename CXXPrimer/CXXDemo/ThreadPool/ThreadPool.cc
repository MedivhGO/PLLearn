#include "ThreadPool.h"

#include <muduo/base/Exception.h>

#include <boost/bind.hpp>
#include <assert.h>
#include <stdio.h>


using namespace muduo;

//构造参数为线程池的名称
ThreadPool::ThreadPool(const string& name) : mutex_(), cond_(mutex_), name_(name), running_(false)
{

}
ThreadPool::~ThreadPool()
{
	if (running_) //线程池处于运行状态,停止线程池
	{
		stop();
	}
}
//启动固定线程池
void Thread::start(int numThreads)
{
	assert(threads_.empty());//断言当前线程池为空
	running_ = true;//置线程池处于运行的状态
	threads_.reserve(numThreads);//预留那么多个空间
	for (int i = 0; i < numThreads; ++i) {
		//循环创建线程
		char id[32];
		//线程号
		snprintf(id, sizeof id, "%d", i);
		threads_.push_back(new muduo::ThreadPool(boost::bind(&ThreadPool::runInThread, this), name_ + id));
		threads_[i].start();
	}
}
//关闭线程池
void ThreadPool::stop()
{
	{
		MutexLockGuard lock(mutex_);
		running_ = false; //running设置为false
		cond_.notifyAll(); //通知所有线程
	}
	//等待线程退出
	for_each(threads_.begin(), threads_.end(), boost::bind(&muduo::ThreadPool::join, _1));
	
	//添加任务
	

}
void ThreadPool::run(const Task& task)
{ //将任务添加到线程池当中的任务队列
	if (threads_.empty())  //如果线程池当中的线程是空的
	{
		task(); //直接执行任务
	}
	else {//否则添加

		MutexLockGuard lock(mutex_);
		queue_.push_back(task);
		cond_.notify(); //通知队列当中有任务了

	}

}
//获取任务函数
ThreadPool::Task ThreadPool::take()
{
	//加锁保护
	MutexLockGuard lock(mutex_);
	//always use a while_loop, due to  spurious wakeup
	//如果队列为空且处于运行状态
	while (queue_.empty() && running_) {
		cond_.wait(); //等待
	}
	Task task; //定义任务变量，Task是一个函数类型
	if (!queue_.empty()) //有任务到来
	{
		task = queue_.front(); //取出任务
		queue_.pop_front(); //弹出任务
	}
	return task;
}
void ThreadPool::runInThread()
{
	try 
	{
		while (running_)
		{
			//获取任务
			Task task(take());
			if (task)
			{
				task();
			}

		}
	}
	catch (const Exception& ex)
	{
		fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
		fprintf(stderr, "reason: %s\n", ex.what());
		fprintf(stderr, "stack trace: %s\n", ex.stackTrace());
		abort();
	}
	catch (const std::exception& ex)
	{
		fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
		fprintf(stderr, "reason: %s\n", ex.what());
		abort();
	}
	catch (...)
	{
		fprintf(stderr, "unknown exception caught in ThreadPool %s\n", name_.c_str());
		throw; // rethrow
	}

}
