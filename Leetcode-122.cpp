#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans =0;
        for(int i=0;i<n-1;i++){
            int x = prices[i];
            int y = -1;
            for(int j=i+1;j<n;j++){
                // cout<<x<<" "<<prices[j]<<'\n';
              if(y>prices[j]){
                if(y!=-1){
                    ans+=(y-x);
                    i=j-1;
                    y=-1;
                    // cout<<"ANS "<<ans<<'\n';
                    break;
                }
                else{
                    x=prices[j];
                }
                
              }
              else{
                // cout<<prices[j]<<" ";
                if(x>prices[j]){
                    x=prices[j];
                    y=-1;
                }else{
                     y = prices[j];
                }
               
              }
            }
            if(y!=-1){
                ans+=y-x;
                break;
            }
        }
        // cout<<ans<<'\n';
        return ans;
    }
};
void solve() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4,2,8};
    
    
    sol.maxProfit(prices);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
