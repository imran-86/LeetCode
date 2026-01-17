#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
 private : 
   void generateSubset(vector<int>&nums,vector<int>output,vector<vector<int>>&result){
      if(nums.size()==0){
         result.push_back(output);
         return;
      }

      vector<int>output1 = output;
      vector<int>output2 = output;
      output2.push_back(nums[0]);
      vector<int> newNums(nums.begin() + 1, nums.end()); 
      generateSubset(newNums,output1,result);
      generateSubset(newNums,output2,result);
      return;
   }
    

public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>output;

      vector<vector<int>>result;
      generateSubset(nums,output,result);
      
      return result;

        
    }
};

void solve() {
    Solution sol;
    std::vector<int> nums;
     nums = {1,2,3};
     sol.subsets(nums);

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