template<int inst>//非类型模板参数
class MallocAllocTemplate//一级空间配置器(malloc,free,realloc)
{
public:
    static void* Allocate(size_t n)
    {
        void* ret = malloc(n);
        if (0 == ret)
            ret = OomMalloc(n);
        return ret;
    }
    static void Deallocate(void* p)
    {
        free(p);
    }
    static void* Reallocate(void* p, size_t newsize)
    {
        void* ret = realloc(p, newsize);
        if (ret == 0)
            ret = OomRealloc(p, newsize);
        return ret;
    }
private:
    static void* OomMalloc(size_t n)//调用自定义的句柄处理函数释放并分配内存
    {
        ALLOC_FUN hander;
        void* ret;
        while (1)
        {
            hander = MallocAllocHander;
            if (0 == hander)
            {
                cout << "Out of memory" << endl;
                exit(-1);
            }
            hander();
            ret = malloc(n);
            if (ret)
            {
                rteurn (ret);
            }
        }
    }
    static void* OomRealloc(void* p, size_t newsize)//同上
    {
        ALLOC_FUN hander;
        void* ret;
        while (1)
        {
            hander = MallocAllocHander;
            if (0 == hander)
            {
                cout << "Out of memory" << endl;
                exit(-1);
            }
            hander();
            ret = realloc(p,newsize);
            if (ret)
            {
                rteurn(ret);
            }
        }
    }
    static void(*SetMallocHandler(void(*f)()))();//设置操作系统分配内存失败时的句柄处理函数
    static ALLOC_FUN MallocAllocHander;

};
template<int inst>
ALLOC_FUN MallocAllocTemplate<inst>::MallocAllocHander = 0;//句柄函数初始化为0