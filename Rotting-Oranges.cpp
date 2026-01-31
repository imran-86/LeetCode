#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public : 
  void bfs(vector<vector<int>>&grid,
    vector<vector<bool>>&visited,queue<pair<int,int>>&q,int &freshOranges){
    auto [x,y]=q.front();
    visited[x][y]=true;
    int xAxis[]= {-1,0,1,0};
    int yAxis[]= {0,1,0,-1};
    queue<pair<int,int>>newQ=q;
    int row = grid.size();
    int col = grid[0].size();
    while(!newQ.empty()){
        auto [x,y]=newQ.front();
        newQ.pop();
        q.pop();
        for(int i=0;i<4;i++){
            int newX = x + xAxis[i];
            int newY = y + yAxis[i];
            if(newX>=0 and newX<row and newY>=0 and newY<col
            and grid[newX][newY]==1 and !visited[newX][newY]){
               q.push({newX,newY});
               grid[newX][newY]=2;
               visited[newX][newY]=true;
               freshOranges--;
            }
        }
    }
  }
public:
    int orangesRotting(vector<vector<int>>&grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        queue<pair<int,int>>q;
        int freshOranges = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0) return 0;  

int i;
for(i = 1; i <= 100; i++){
    if(q.empty()) break; 
    
    int preFreshOrange = freshOranges;
   
    bfs(grid, visited, q, freshOranges);
     // cout<<preFreshOrange<<" "<<freshOranges<<'\n';
    
    if(freshOranges == 0){  
        // cout<<i<<"\n";
        return i;
    }
    
    if(preFreshOrange == freshOranges && !q.empty()){  
        return -1; 
    }
}

return freshOranges == 0 ? i : -1; 
        
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>grid;
    grid = {
  {2,1,1},
  {0,1,1},
  {1,0,1}
};
    cout<<sol.orangesRotting(grid)<<'\n';

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