#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,char>m;
        for(int i=0;i<26;i++){
            m[order[i]]= ('a'+i);
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j]= m[words[i][j]];
            }
        }
        return is_sorted(words.begin(),words.end());
    }
};
void solve() {
    Solution sol;
    cout<<sol.isAlienSorted(words,order)<<'\n';

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