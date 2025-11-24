#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int len = nums.size()-1;
        vector<int>suffix(len+1),preffix(len+1);
         int max_product = -11;
         int maxi = -11;
        preffix[0]=nums[0];
        suffix[len]=nums[len];
        for(int i=1;i<=len;i++){
              preffix[i] = nums[i]*preffix[i-1];
              if(preffix[i]==0){
                preffix[i]=nums[i];
              }
        }
        for(int i=len-1;i>=0;i--){
            suffix[i] = nums[i]*suffix[i+1];
            if(suffix[i]==0){
                suffix[i]=nums[i];
            }
        }
       
        for(int i=0;i<=len;i++){
           
           max_product = max(preffix[i],suffix[i]);
           maxi = max(maxi,max_product);
           
        }
       
        // cout<<maxi<<'\n';
        return maxi;
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
   
     sol.maxProduct(nums);
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