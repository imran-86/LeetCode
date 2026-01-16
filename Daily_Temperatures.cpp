#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int size = temperatures.size();
        vector<int>ans(size);
        for(int i=0;i<temperatures.size();i++){
          if(st.empty() or (!st.empty() and st.top().first >= temperatures[i])){
            st.push({temperatures[i],i});
          }
          else{
            if(st.top().first<temperatures[i]){
                while(!st.empty() and st.top().first<temperatures[i]){
                  int waitDays = abs(i-st.top().second);
                  ans[st.top().second] = waitDays;
                  st.pop();
                }
                st.push({temperatures[i],i});
                
            }
          }
          
        }

        return ans;
       
  }  
};

void solve() {
    Solution sol;
    vector<int>temperatures = {90,90,90};
    sol.dailyTemperatures(temperatures);
    // cout<<sol.dailyTemperatures(temperatures)<<'\n';

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