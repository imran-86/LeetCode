#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: int bfs(int row,int col,vector<vector<int>>& grid,
    vector<vector<bool>>&visited){
    queue<pair<int,int>>q;
    q.push({0,0});
    int dx[]={-1,-1,-1,1,1,1,0,0};
    int dy[]={-1,0,1,-1,0,1,-1,1};
    int gridSize = grid.size();
    int distance = 1;
    while(!q.empty()){
        int size = q.size();
        for(int s = 0;s<size;s++){
           auto [x,y]=q.front();
        q.pop();
        if(x==gridSize-1 and y==gridSize-1){
            return distance;
        }
        for(int i=0;i<8;i++){
            int r = x + dx[i];
            int c = y + dy[i];
            if(r>=0 and r<row and c>=0 and
            c<col and !visited[r][c] and grid[r][c]==0){
               visited[r][c]=true;
               q.push({r,c});
            }
        }
       
        }
         distance++; 
        
    }
    return -1;

}
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>>visited(row,vector<bool>(col,
            false));
        visited[0][0]=true;
        int ans = bfs(row,col,grid,visited);
        // cout<<ans<<'\n';
        return ans;
       
    }
};
void solve() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,1,0}
    };
    
    cout << sol.shortestPathBinaryMatrix(grid) << '\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
