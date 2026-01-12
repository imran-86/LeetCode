#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack<char>st;
        while(i<s.size()){
             if(s[i]==')' and !st.empty() and st.top()=='('){
                st.pop();
                i++;
             }
             else if(s[i]=='}' and !st.empty() and st.top()=='{'){
                st.pop();
                i++;
             }
             else if(s[i]==']' and !st.empty() and st.top()=='['){
                st.pop();
                i++;
             }
             else if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
                i++;
             }
             else{
                return false;
             }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};

void solve() {
    Solution sol;
    string st;
    st = "]";
    cout<<sol.isValid(st)<<'\n';

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