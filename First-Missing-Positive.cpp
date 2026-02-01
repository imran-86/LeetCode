#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int>m;
        for(int i =0;i<len;i++){
            if(nums[i]>=0){
                 m[nums[i]]=1;
            }
         
        }
        int positiveLen =m.size();
       
        for(int i=1;i<=positiveLen;i++){
            if(!m[i]){
            return i;
            }
        }
        return positiveLen+1;
    }
};
void solve() {
    Solution sol;
     vector<int>nums;
     nums = {7,8,9,11,12};
    cout<<sol.firstMissingPositive(nums)<<'\n';

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