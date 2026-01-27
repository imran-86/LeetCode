#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int islandPerimeter(vector<vector<int>>&grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]){
                    ans+=4;
                    if(j+1<col and grid[i][j+1]){
                        ans-=2;
                    }
                    if(i>0 and grid[i-1][j]){
                        ans-=2;
                    }
                }
            }
        }
        cout<<ans<<'\n';
        return ans;
        
    }
};

void solve() {
    Solution sol;
    vector<vector<int>>grid;
    grid = {{1}};
     sol.islandPerimeter(grid);

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