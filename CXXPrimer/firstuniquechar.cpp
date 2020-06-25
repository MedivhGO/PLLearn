#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unique(nums1.begin(),nums1.end());
    for(int i=0;i<nums1.size();i++)
    {
        vector<int> :: iterator it =
        find(nums2.begin(),nums2.end(),nums1[i]);
        while(it!=nums2.end())
        {
            result.push_back(nums1[i]);
            it = find(it+1,nums2.end(),nums1[i]);
        }
    }
    return result;
}int main()
{
    vector<int> vec1 = {1,2,2,1};
    vector<int> vec2 = {2,2};
    vector<int> vec = intersect(vec1,vec2);
    for(auto x:vec)
    {
        cout << x << " ";
    }
}
