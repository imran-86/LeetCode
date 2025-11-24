#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findSum(nums, goal) - findSum(nums, goal - 1);
    }

private:
    int findSum(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int len = nums.size();
        int count = 0;
        
        while(r < len) {
            sum += nums[r];
            
            while(sum > k && l <= r) {
                sum -= nums[l];
                l++;
            }
            
            count += (r - l + 1);
            r++;
        }
        return count;
    }
};


void solve() {
    Solution sol;
    vector<int>nums;
    int x;
    while(cin >> x) {
        nums.push_back(x);
        if(cin.peek() == '\n') break; 
    }
    int goal;cin>>goal;
     int sum1 = sol.numSubarraysWithSum(nums,goal);
     int sum2 = sol.numSubarraysWithSum(nums,goal-1);
     cout<<sum1<<" "<<sum2<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int t=1;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;

}