#pragma once
#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>
#include <muduo/base/Thread.h>
#include <muduo/base/Types.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <deque>

namespace muduo
{
	class ThreadPool : boost::noncopyable
	{
	public:
		typedef boost::function<void()> Task;

		explicit ThreadPool(const string& name = string());
		~ThreadPool();


		void start(int numThreads);//启动线程池

		void run(const Task& f);

	private:
		//线程池当中的线程要执行的函数
		void runInThread();
		//获取任务
		Task take();

		MutexLock mutex_;
		Condition cond_;
		string name_; //线程池名称
		boost::ptr_vector<muduo::Thread> threads_;//存放线程指针
		std::deque<Task> queue_; //任务队列
		bool running_;//线程池是否处于运行的状态
	};
}