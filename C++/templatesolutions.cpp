template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem *ptr, elemType value);
private:
	ListItem *front, *end;
};

//solutions16.11

template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};

int main()
{
    return 0;
}


//solutions16.12
//编写你自己版本的 Blob 和 BlobPtr 模版，包含书中未定义的多个const成员。
#ifndef STRBLOB_H_
#define STRBLOB_H_

#include <string>
#include <initializer_list>
#include <memory>
#include <vector>
#include <stdexcept>

template <typename T>
class ConstStrBlobPtr;

template <typename T>
class StrBlob
{
public:
    friend class ConstStrBlobPtr<T>;

    typedef typename std::vector<T>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    ConstStrBlobPtr<T> begin();
    ConstStrBlobPtr<T> end();
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const T &msg) const;
};

template <typename T>
class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr<T>() : curr(0){};
    ConstStrBlobPtr<T>(const StrBlob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T& deref() const;
    ConstStrBlobPtr<T>& incr();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const T&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> ConstStrBlobPtr<T>::check(std::size_t i, const T &msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr<T>");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T>
T& ConstStrBlobPtr<T>::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
ConstStrBlobPtr<T>& ConstStrBlobPtr<T>::incr()
{
    check(curr, "increment past end of ConstStrBlobPtr<T>");
    ++curr;
    return *this;
}

template <typename T>
StrBlob<T>::StrBlob() : data(std::make_shared<std::vector<T>>()){}

template <typename T>
StrBlob<T>::StrBlob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)){}

template <typename T>
void StrBlob<T>::check(size_type i, const T &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T & StrBlob<T>::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
T & StrBlob<T>::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
const T& StrBlob<T>::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

template <typename T>
const T& StrBlob<T>::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

template <typename T>
void StrBlob<T>::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

template <typename T>
ConstStrBlobPtr<T> StrBlob<T>::begin() { return ConstStrBlobPtr<T>(*this); }

template <typename T>
ConstStrBlobPtr<T> StrBlob<T>::end()
{
    auto ret = ConstStrBlobPtr<T>(*this, data->size());
    return ret;
}

#endif


//solution16.14
//编写 Screen 类模版，用非类型参数定义 Screen 的高和宽。
#ifndef SCREEN_EX23_H_
#define SCREEN_EX23_H_

#include <string>
#include <vector>

// template <unsigned W, unsigned H>
// class Screen;

// template <unsigned W, unsigned H>
// class Window_mgr
// {
// public:
//     using ScreenIndex = std::vector<Screen<W,H>>::size_type;
//     void clear(ScreenIndex<W,H>);
// private:
//     std::vector<Screen<W,H>> screens;
// };

template <unsigned W, unsigned H>
class Screen 
{
// friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(char c) : contents(H*W, c){ }

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {do_display(os); return *this;}
    const Screen &display(std::ostream &os) const {do_display(os); return *this;}
    // pos size() const;

private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents;}
};


template <unsigned W, unsigned H>
inline Screen<W, H> &Screen<W, H>::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template <unsigned W, unsigned H>
inline Screen<W, H> &Screen<W, H>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <unsigned W, unsigned H>
inline Screen<W, H> &Screen<W, H>::set(pos r, pos col, char c)
{
    contents[r*width + col] = c;
    return *this;
}

// template <unsigned W, unsigned H>
// Screen<W, H>::pos Screen<W, H>::size() const
// {
//     return height * width;
// }

// void Window_mgr::clear(ScreenIndex i)
// {
//     Screen &s = screens[i];
//     s.contents = std::string(s.height * s.width, ' ');
// }

#endif

