#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>m;
        int len = bills.size();
        for(int i=0;i<len;i++){
            if(bills[i]==5){
                m[5]++;
            }
            else if(bills[i]==10 and m[5]){
                m[5]--;
                m[10]++;
            }
            else if(bills[i]==20 and m[5]){
                if(!m[10]){
                    if(m[5]>2){
                        m[5]-=3;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    m[10]--;
                    m[5]--;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
void solve() {
    Solution sol;
    vector<int>bills;
    int x;
    while(cin >> x) {
        bills.push_back(x);
        if(cin.peek() == '\n') break; 
    }
   
    cout << sol.lemonadeChange(bills)<< '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;

}