#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        map<char,int>ma;
        int len = 0;
        int ans = -1;
        for(int i=0;i<size;i++){
            
            int r = i+1;
            
            ma[s[i]] = i;
            while(r<size and ma.find(s[r]) == ma.end()){
                ma[s[r]]=r;
                r++;
            }
            len = r - i;
            cout<<i<<" "<<r<<" "<<len<<'\n';
            ans = max(ans,len);
            if(r<size-1){
                i=ma[s[r]];
            }
            else{
                break;
            }
            
            ma.clear();
        }
        return ans == -1 ? 0 : ans;
    }
};

void solve() {
    Solution sol;
    string st;
    st = "";
    cout<<sol.lengthOfLongestSubstring(st)<<'\n';

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