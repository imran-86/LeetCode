#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 and k==1){
          return 0;
        }
        int len = (1<<(n-1));
        int mid = len/2;
        if(k<=mid){
         return kthGrammar(n-1,k);
        }
        else{
         return !kthGrammar(n-1,k-mid);
        }
    }
};

void solve() {
    Solution sol;
    int n=2,k=1;
    cout<<sol.kthGrammar(n,k)<<'\n';
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