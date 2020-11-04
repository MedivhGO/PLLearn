#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    vector<int> ivec{1,3,5,7,9,11,13};
    ostream_iterator<int> out_iter(cout," ");
    copy(ivec.begin(),ivec.end(),out_iter);
    cout << endl;
    cout << distance(ivec.begin(),ivec.end());
    cout << endl;
    vector<int>::iterator iter = lower_bound(ivec.begin(),ivec.end(),2); //返回第一个大于等于val值的元素迭代器
    cout << * iter << endl;
    iter = upper_bound(ivec.begin(),ivec.end(),2);//返回第一个大于val值的迭代器
    cout << *iter << endl;
}
