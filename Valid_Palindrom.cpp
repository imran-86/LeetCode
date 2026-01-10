#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = "";
        for(char x : s){
            if(isalnum(x)){
                cleanString+=tolower(x);
            }
        }
        int l=0;
        int r=cleanString.size()-1;
        while(l<=r){
            if(cleanString[l]!=cleanString[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};



void solve() {
    Solution sol;
    string s;
    s = "race a car";
   
    cout<<sol.isPalindrome(s)<<"\n";

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