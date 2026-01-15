#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
          if(tokens[i]== "+" or tokens[i]=="/" or tokens[i]=="*" or tokens[i]=="-"){
            int first = (st.top());
            st.pop();
            int second = (st.top());
            st.pop();
            if(tokens[i]=="/"){
              int result = second/first;
              cout<<result<<'\n';
              st.push(result);
            }
            else if(tokens[i]=="*"){
              int result = second*first;
              st.push(result);
            }
            else if(tokens[i]=="+"){
              int result = second+first;
              cout<<result<<'\n';
              st.push(result);
            }
            else if(tokens[i]=="-"){
              int result = second-first;
              st.push(result);
            }
          }
          else{
            int num = stoi(tokens[i]);
            st.push(num);
          }
        }
        // cout<<st.top()<<'\n';
        return st.top();
    }
};

void solve() {
    Solution sol;
    vector<string>tokens = {"4","13","5","/","+"};
    cout<<sol.evalRPN(tokens)<<'\n';

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