#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
  public : 
  void dfs(vector<vector<char>>&grid,int r,int c,int maxRow,int maxCol){

    if(r>=maxRow or r<0 or c>=maxCol or c<0 or grid[r][c]=='0'){
        return;
    }
    grid[r][c]='0';
    dfs(grid,r-1,c,maxRow,maxCol);
    dfs(grid,r,c-1,maxRow,maxCol);
    dfs(grid,r+1,c,maxRow,maxCol);
    dfs(grid,r,c+1,maxRow,maxCol);
  }
public:
    int numIslands(vector<vector<char>>&grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                  if(grid[i][j]=='1'){
                      count++;
                      dfs(grid,i,j,row,col);
                  }
             }
        }
        // cout<<count<<'\n';
        return count;
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
    cout<<sol.numIslands(grid)<<'\n';

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