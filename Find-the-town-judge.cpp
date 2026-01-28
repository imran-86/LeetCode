#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> trustCount;  
        
        for(auto& t : trust) {
            int a = t[0], b = t[1];
            adjList[a].push_back(b);  
            trustCount[b]++;          
        }
        
       
        for(int i = 1; i <= n; i++) {
         
            if(adjList[i].size() == 0) {
               
                if(trustCount[i] == n - 1) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
void solve() {
    Solution sol;
    int n=4;
    vector<vector<int>>trust;
    trust = {{1,3},{1,4},{2,3}};
    sol.findJudge(n,trust);

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