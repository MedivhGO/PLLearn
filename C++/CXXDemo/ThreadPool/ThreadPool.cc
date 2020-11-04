#include "ThreadPool.h"

#include <muduo/base/Exception.h>

#include <boost/bind.hpp>
#include <assert.h>
#include <stdio.h>


using namespace muduo;

//�������Ϊ�̳߳ص�����
ThreadPool::ThreadPool(const string& name) : mutex_(), cond_(mutex_), name_(name), running_(false)
{

}
ThreadPool::~ThreadPool()
{
	if (running_) //�̳߳ش�������״̬,ֹͣ�̳߳�
	{
		stop();
	}
}
//�����̶��̳߳�
void Thread::start(int numThreads)
{
	assert(threads_.empty());//���Ե�ǰ�̳߳�Ϊ��
	running_ = true;//���̳߳ش������е�״̬
	threads_.reserve(numThreads);//Ԥ����ô����ռ�
	for (int i = 0; i < numThreads; ++i) {
		//ѭ�������߳�
		char id[32];
		//�̺߳�
		snprintf(id, sizeof id, "%d", i);
		threads_.push_back(new muduo::ThreadPool(boost::bind(&ThreadPool::runInThread, this), name_ + id));
		threads_[i].start();
	}
}
//�ر��̳߳�
void ThreadPool::stop()
{
	{
		MutexLockGuard lock(mutex_);
		running_ = false; //running����Ϊfalse
		cond_.notifyAll(); //֪ͨ�����߳�
	}
	//�ȴ��߳��˳�
	for_each(threads_.begin(), threads_.end(), boost::bind(&muduo::ThreadPool::join, _1));
	
	//�������
	

}
void ThreadPool::run(const Task& task)
{ //��������ӵ��̳߳ص��е��������
	if (threads_.empty())  //����̳߳ص��е��߳��ǿյ�
	{
		task(); //ֱ��ִ������
	}
	else {//�������

		MutexLockGuard lock(mutex_);
		queue_.push_back(task);
		cond_.notify(); //֪ͨ���е�����������

	}

}
//��ȡ������
ThreadPool::Task ThreadPool::take()
{
	//��������
	MutexLockGuard lock(mutex_);
	//always use a while_loop, due to  spurious wakeup
	//�������Ϊ���Ҵ�������״̬
	while (queue_.empty() && running_) {
		cond_.wait(); //�ȴ�
	}
	Task task; //�������������Task��һ����������
	if (!queue_.empty()) //��������
	{
		task = queue_.front(); //ȡ������
		queue_.pop_front(); //��������
	}
	return task;
}
void ThreadPool::runInThread()
{
	try 
	{
		while (running_)
		{
			//��ȡ����
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
