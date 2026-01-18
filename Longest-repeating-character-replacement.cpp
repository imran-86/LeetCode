#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int ans = 0;
        int j;
        for(int i = 0; i < size; i++) {
      
            int replace = 0;
            int firstDiffer = -1;
            
            for(j = i; j < size; j++) {
                if(s[i] != s[j]) {
                    replace++;
                    if(replace == 1) {
                        firstDiffer = j;
                        
                    }
                }
                if(j==size-1){
                  int length = 0;
                  if(k-replace>=0){
                    length = j - i + 1;
                    // cout<<lengthB<<'\n';
                    length+=(k-replace);
                    int mini = min(size,length);
                    ans = max(ans,mini);
                    
                  }
                  else{
                    length = j-i;
                    ans = max(ans,length);
                  
                  }
                
                }
                else if(replace>k){
                    ans = max(ans,j-i);
                    break;
                }
                
            }
            
           
            if(firstDiffer != -1) {
                i = firstDiffer - 1;  
            } 
            
            
        }
        
        return ans;
    }
};
void solve() {
    Solution sol;
    string s = "CADBBB";
    int k=4;
     cout<<sol.characterReplacement(s,k)<<'\n';

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