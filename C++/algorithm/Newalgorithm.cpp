#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include <list>
using namespace std;
void sop(vector<int> &ivec) {
    for(auto x : ivec) {
        cout << x << " ";
    }

}
int main()
{
    int ia[] = {27,210,12,47,109,83};
    int val = 83;
    int *result = find(begin(ia),end(ia),val);
    cout << *result <<endl;
    vector<int> ivec{1,2,3,4,5,6,7,8,9};
    
     /*
        sum
      
    */
    int sum = accumulate(begin(ia),end(ia), 0);
    cout << sum <<endl;
    
    vector<string> svec = {"aa","bb","cc","dd","ee"};
    
    string ssum = accumulate(svec.begin(),svec.end(),string(""));
    cout << ssum << endl;
    vector<double> dvec = {3.14,1.11,12.4};
    
    int dsum = accumulate(dvec.begin(), dvec.end(), 0);
    
    cout << dsum << endl;
    
    list<const char*> csvec{"aaa","bb","ccc"};
    list<const char*> csvec1{"aaa","bb","ccc"};
   // bool res =  equal(csvec.begin(), csvec.end(), csvec1.begin(), csvec1.end());
   // cout << res <<endl;
    
    
    /*
        fill 函数及 fill_n
     
     */
    fill(ivec.begin(),ivec.end(),0);
    for(auto x : ivec) {
        cout << x << " ";
    }
    cout << endl;
    fill_n(ivec.begin(),3,11);
    for(auto x : ivec) {
        cout << x << " ";
    }
    cout << endl;
    /*
        insert_back() 函数
     */
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42;
    sop(vec);
    cout << endl;
    
    /*
         copy_algorithm
     */
    
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];
    
    auto ret  = copy(begin(a1), end(a1), a2);
    vector<int> ivec2(begin(a2),ret);
    sop(ivec2);
    cout << endl;
    /*
     
     replace
     
     */
    list<int> ilist(begin(a1),end(a1));
    replace(ilist.begin(), ilist.end(), 1, 100);
    for(auto x:ilist) {
        cout << x << " ";
    }
    cout << endl;
    list<int> ilist2(ilist.size(),0);
    replace_copy(ilist.begin(), ilist.end(), ilist2.begin(), 0, 111);
    for(auto x:ilist2) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<int> iivec;
    iivec.reserve(10);
    fill_n(iivec.begin(), 10, 0);
    cout <<"vector size: " <<iivec.size() << endl;
    
}
