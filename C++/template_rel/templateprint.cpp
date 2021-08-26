#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <iterator>

template <typename T>
void print(T t);

template<typename Kt,typename Vt>
void print(std::pair<Kt,Vt> kv)
{
	print(kv.first);
	print("=");
	print(kv.second);
}
template <typename T>
void print(T t)
{
	std::cout << t;
}
template<typename T,typename AllocT,template<typename,typename...> typename SequenceT>
void print(SequenceT<T, AllocT> seq)
{
	print("{");
	for(auto iter=std::begin(seq); iter!=std::end(seq);iter=std::next(iter)) {
		print(*iter);
		print(",");
	}
	print("\b}"); //加了\b格式就整齐了
}

int main()
{
	std::vector<std::vector<int> > vec{
		{1,3},
		 {-2,2}};
		
	std::vector<int> ivec{1,2,3};
	print(ivec);
	return 0;
}
