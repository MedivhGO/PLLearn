//
// Created by Lee on 2018/6/29.
//

#ifndef APUE_MUTEXLOCK_H
#define APUE_MUTEXLOCK_H

#include "noncopyable.h"
#include  <pthread.h>
#include <cstdio>
class MutexLock : noncopyable
{
public:
    MutexLock()
    {
        pthread_mutex_init(&mutex,NULL);
    }
    ~MutexLock()
    {
        pthread_mutex_lock(&mutex);
        pthread_mutex_destroy(&mutex);
    }
    void lock()
    {
        pthread_mutex_lock(&mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_t* get()
    {
        return &mutex;
    }
private:
    pthread_mutex_t mutex;

private:
    friend class Condition;
};

class MutexLockGuard
{
public:
    explicit  MutexLockGuard(MutexLock& _mutex):m(_mutex)
    {
        m.lock();
    }
    ~MutexLockGuard()
    {
        m.unlock();
    }
private:
    MutexLock& m;
};
#endif //APUE_MUTEXLOCK_H
