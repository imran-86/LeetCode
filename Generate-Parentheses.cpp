#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {

public: 
    void fun(int open,int close,string output,vector<string>&v){
        if(open==0 and close==0){
            v.push_back(output);
            return;
        }
        if(open!=0){
            string op1 = output;
            op1.push_back('(');
            fun(open-1,close,op1,v);
            
        }
        if(close>open){
            string op2 = output;
            op2.push_back(')');
            fun(open,close-1,op2,v);
            
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string output = "";
        int open = n;
        int close = n;
        fun(open,close,output,v);
        return v;
    }
};
void solve() {
    Solution sol;
    int n = 1;
     sol.generateParenthesis(n);

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