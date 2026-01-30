#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
  public : 
  int dfs(vector<vector<int>>&grid,int r,
    int c,int maxRow,int maxCol){

    if(r>=maxRow or r<0 or c>=maxCol or c<0 or grid[r][c]==0){
        return 0;
    }
    grid[r][c]=0;
    int ans = 1;
    ans+=dfs(grid,r-1,c,maxRow,maxCol);
    ans+= dfs(grid,r,c-1,maxRow,maxCol);
    ans+= dfs(grid,r+1,c,maxRow,maxCol);
    ans+= dfs(grid,r,c+1,maxRow,maxCol);
    return ans;
  }
public:
    int maxAreaOfIsland(vector<vector<int>>&grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = -1;
        
        for(int i=0;i<row;i++){
            int oneArea=0;
             for(int j=0;j<col;j++){
                  if(grid[i][j]==1){
                     oneArea = dfs(grid,i,j,row,col);
                  }
                   maxArea = max(maxArea,oneArea);
                  
             }
        }
        return maxArea;
    }
};
void solve() {
    Solution sol;
    vector<vector<char>>grid;
    grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
};
    cout<<sol.maxAreaOfIsland(grid)<<'\n';

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