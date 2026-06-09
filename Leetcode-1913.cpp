#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        return (nums[len-1]*nums[len-2]) - (nums[0]*nums[1]);
    }
};

void solve() {
    Solution sol;
    vector<int>nums = {4,2,5,9,7,4,8};
    
    cout<<sol.maxProductDifference(nums)<<'\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
