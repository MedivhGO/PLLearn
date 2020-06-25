#pragma once
template <class _Tp>
class auto_ptr {
private:
	_Tp* _M_ptr;
public:
	typedef _Tp element_type;
	explicit auto_ptr(_Tp* __p = 0) : _M_ptr(__p) {}
	auto_ptr(auto_ptr& __a) : _M_ptr(a.release()) {}

	auto_ptr& operator= (auto_ptr& __a) {
		if (&__a != this) {
			delete _M_ptr; //删除原来的ptr所指向的对象;
			_M_ptr = __a.release(); //释放a._M_ptr所指向的对象的控制权,,并赋值
		}
		return *this;
	}
	~auto_ptr() { delete _M_ptr; }

	_Tp& operator*() { return *_M_ptr; }
	_Tp* operator->() { return *_M_ptr; } 
	// _Tp* opeerator->() {return &(operator*());}

	_Tp* get() const
	{
		return _M_ptr;
	}

	_Tp* release() {
		_Tp* __tmp = _M_ptr; //赋给一个临时变量，出作用域后会被销毁
		_M_ptr = 0;
		return __tmp;
	}

	void reset(_Tp* __p = 0)
	{
		if (__p != _M_ptr) {
			delete _M_ptr;
			_M_ptr = __p;
		}
	}

	/*
		1. 直接调用release后，因为realse本身不会释放保存的指针内存，所以会造成内存泄露。

		2. 唯一传递性，传递给其他auto_ptr对象，当前的对象就不在拥有对该指针的控制权。
	
	*/
};
template <class T> class scoped_ptr
{
private:
	T* px;
	scoped_ptr(scoped_ptr const& x);
	scoped_ptr& operator=(scoped_ptr const& x);
	typedef scoped_ptr<T> this_type;

	void operator == (scoped_ptr const&) const;
	void operator != (scoped_ptr const&) const;

public:
	typedef T element_type;
	explicit scoped_ptr(T* p = 0) : px(p);

	~scoped_ptr()
	{
		boost::checked_delete(px);
	}

	void reset(T* p = 0) {
		BOOST_ASSERT(p == 0 || p != px);
		this_type(p).swap(*this);
	}
	T& operator*() const {
		BOOST_ASSERT(px != 0);
		return *px;
	}
	T* operator->() const {
		BOOST_ASSERT(px != 0);
		return &(operator*());
	}
	T *get() const
	{
		return px;
	}
	void swap(scoped_ptr& b) {
		T* tmp = b->px;
		b->px = px;
		px = tmp;
	}
};