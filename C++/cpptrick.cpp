#include <bits/stdc++.h> // 包含常用的头文件 algorithm bitset等
using namespace std;

#define all(x) (x).begin(), (x).end()

int main()
{
    vector<int> ivec{1,5,2,2,53,342,10,-1};
    int res = min({1,5,2,2,53,342,10,-1}); // 得到这些字面值的最小值
    cout << res << endl;
    sort(all(ivec));
    std::string sep = "";
    for (auto x : ivec) {
        cout << sep + to_string(x);
        sep = " ";
    }
    cout << endl;
    int bit_data = 12;
    // 正常的人类阅读二进制的顺序
    cout << bitset<20>(bit_data) << endl; // boolean vector会是使用相反的顺序
    return 0;
}