#include <iostream>
#include <vector>
#include <string>
using namespace std;


template <typename > class BlobPtr; //使得BlobPtr在Blob中可见
template <typename > class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }

    void push_back(T&& t) { data->push_back(std::move(t)); }

    void pop_back();

    T& back();
    T& operator[](size_type i);

    friend class BlobPtr<T>;
    friend bool operator==<T>
        (const Blob<T>&, const Blob<T>&);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};
template<typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
template<typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}
template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
    data(std::make_shared<std::vector<T>>(il)) {}

template <typename T> class BlobPtr {
public:
    BlobPtr() : cur(0) { }
    BlobPtr(Blob<T>& a, size_t sz = 0) : wptr(a.data), curr(sz) { }

    T& operator*() const
    {
        auto p = check(curr, "deference past end");
        return (*p)[curr];
    }

    BlobPtr& operator++(); //前置++ , 在模板类的作用域,省略<T>
    BlobPtr& operator--();
    BlobPtr operator++(int);
};
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++* (this);
    return ret;
}

template <typename > class BlobPtr;
template <typename > class Blob; //运算符==中的参数所需要



template <typename T> class Blob {

};



int main(int argc, char* argv[]) {

    cout << "Hello World!" << endl;
    Blob<char> ca;
    Blob<int> ia;

    //BlobPtr<char>的成员可以访问ca(或任何其他Blob<char>)对象的非public部分,但是ca对ia或Blob的任何其他实例都没有
    //特殊的访问权限.    
}