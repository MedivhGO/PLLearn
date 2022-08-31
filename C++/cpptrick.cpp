//#include <bits/stdc++.h> // 包含常用的头文件 algorithm bitset等
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

#define all(x) (x).begin(), (x).end()

int main()
{
    vector<int> ivec{1, 5, 2, 2, 53 ,342 ,10 ,-1};
    int res = min({1, 5, 2, 2, 53 ,342 , 10, -1}); // 得到这些字面值的最小值
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
    cout << bitset<20>(bit_data) << endl;

    cout << bitset<20>(bit_data)[0] << endl;
    cout << bitset<20>(bit_data)[1] << endl;
    cout << bitset<20>(bit_data)[2] << endl; // 实际下标为字符串从右往左依次递增
    cout << bitset<20>(bit_data)[3] << endl;

    return 0;
}