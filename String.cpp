#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int strStr(string haystack, string needle) {
        int it = haystack.find(needle);
        return it;
    }
};
void solve() {
    Solution sol;
   string haystack = "gwgsadbutsad";
   string needle = "sadcc";
    sol.strStr(haystack,needle);

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