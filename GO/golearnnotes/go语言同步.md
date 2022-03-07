Go同步

GO同步着重看Go的Sync库，这个库提供了同步的函数。

WaitGroup：有Add、Done、Wait三个函数，用的比较多，用于阻塞主线程，等待其他routing的完成。

Mutex: Lock 和 UnLock方法，是共享内存一种同步的使用方法。

RWMutext：读写锁，Lock和UnLock是写锁，写的时候别的什么都不能干，而RLock，RUnLock是读锁。

Cond：Wait() signal() broadcast方法，要和Mutxt的Lock和UnLock配合起来使用。

Once，确保放到其中的function只执行一次。

Go并发

Go采用CSP，有缓冲和非缓冲两种用法。
其中对于非缓冲的，类似于泳池接力，一个到达，另外一个才能走。

对于缓冲的chan，类比送信，如果信箱没有满，则送完就可以走，不用等待，只有信箱满了，才需要等待。