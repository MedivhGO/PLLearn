class ThreadPool
{
    public:

        //定义构造方法
        ThreadPool(size_t thread); // 可以容纳的线程数

        template<typename F, typename... Args>
        auto enqueue(F&& f,Args&&... args)
        ->std::future<typename std::result_of<F(Args...)>::type>;//result_of 返回一个可调用对象的


        ~ThreadPool();

    private:
        //需要持续追踪线程来保证可以使用join
        std::vector<std::thread> workers;
        //任务队列
        std::queue<std::function<void()>> tasks;

        //同步相关
        std::mutex queue_mutex;
        std::condition_variable condition;


        bool stop;
}
inline ThreadPool::ThreadPool(size_t threads):stop(false){

    for (size_t i = 0; i < threads; ++i) 
        workers.emplace_back(
            [this]{

                for (;;) {
                    //定义函数对象的容器，存储任意类型的返回类型为 void 参数列表为空的函数
                    std::function<void()> task;
                    //临界区
                    {
                        //创建互斥锁
                        std::unique_lock<std::mutex> lock(this->queue_mutex);

                        this->condition.wait(lock,
                           [this]{return this->stop||!this->tasks.empty();}); //没停 且 不为空 将不会阻塞当前线程。

                        if (this->stop && this->tasks.empty())
                            return ;
                       
                        
                        task = std::move(this->tasks.front());
                        this->tasks.pop();



                    }
                    //执行当前任务
                    task();
                }



            }


        );
}
inline ThreadPool::~ThreadPool()
{
    //临界区
    {
        //创建互斥锁
        std::unique_lock<std::mute>x lock(queue_mutex);

        stop = true;

    }
    //通知所有等待的线程
    condition.notify_all();

    //使所有异步线程转为同步执行
    for(std::thread & worker : workers){
        worker.join();
    }

}
template <class F, class... Args>
auto ThreadPool::enqueue(F&& f,Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    //获得当前任务
    auto task = std::make_shared<std::packaged_task<return_type()>>(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
    //获得 std::future 对象一攻实施线程同步
    std::future<return_type> res= task->get_future();

    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        //禁止在线程池停止后加入新的线程
        if (stop) 
            throw std::runtime_error("enqueue on stopped ThreadPool");


        //将线程添加到执行任务队列中

        tasks.emplace([task]{(*task)();});


    }
    condition.notify_one();

    return res;
}