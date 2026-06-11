#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0,ans =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=i;j<n;j++){
                    if(nums[j]==1){
                        count++;
                        i=j;
                    }
                    else{
                        ans = max(ans,count);
                        // cout<<j<<" "<<ans<<'\n';
                        count = 0;
                        i=j;
                        // cout<<i<<'\n';
                        break;
                    }
                }
            }
        }
        ans = max(ans,count);
        return ans;
    }
};

void solve() {
    Solution sol;
    vector<int>nums = {1,1,0,1,1,1};
    
    cout<<sol.findMaxConsecutiveOnes(nums)<<'\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
