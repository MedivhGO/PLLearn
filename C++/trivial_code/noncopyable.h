//
// Created by Lee on 2018/6/29.
//

#ifndef APUE_NONCOPYABLE_H
#define APUE_NONCOPYABLE_H

class noncopyable
{

protected:
    noncopyable(){}
    ~noncopyable(){}

private:
    noncopyable(const noncopyable&);
    noncopyable&  operator=(const noncopyable&);
};

/*C++11 写法*/

class noncopyableCXX11
{
protected:
    constexpr  noncopyableCXX11() = default;
    ~noncopyableCXX11()() = default;
    noncopyableCXX11(const noncopyable& ) = delete;
    noncopyableCXX11& operator= (const noncopyableCXX11& ) = delete;
};


#endif //APUE_NONCOPYABLE_H
