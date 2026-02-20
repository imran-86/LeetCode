#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& grid, 
             vector<vector<bool>>& visited, queue<pair<int,int>>& q){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> tempQ;  
        tempQ.push({r, c});
        visited[r][c] = true;
        q.push({r, c});  
        
        while(!tempQ.empty()){
            auto [x, y] = tempQ.front();
            tempQ.pop();  
            
            for(int i = 0; i < 4; i++){
                int posx = x + dx[i];
                int posy = y + dy[i];
                
                if(posx >= 0 && posx < row 
                   && posy >= 0 && posy < col 
                   && !visited[posx][posy] 
                   && grid[posx][posy] == 1){
                    visited[posx][posy] = true;
                    tempQ.push({posx, posy});
                    q.push({posx, posy});  
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int,int>> q;
        
        bool found = false;
        for(int i = 0; i < row && !found; i++){
            for(int j = 0; j < col && !found; j++){
                if(grid[i][j] == 1){
                    bfs(i, j, grid, visited, q);
                    found = true;  
                }
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int distance = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int s = 0; s < size; s++){
                auto [x, y] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int posx = x + dx[i];
                    int posy = y + dy[i];
                    if(posx >= 0 && posx < row 
                       && posy >= 0 && posy < col 
                       && !visited[posx][posy]){
                        
                        if(grid[posx][posy] == 1){
                            return distance;
                        }
                        visited[posx][posy] = true;
                        q.push({posx, posy});
                    }
                }
            }
            
            distance++;
        }
        
        return -1;
    }
};

void solve() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    
    cout << sol.shortestBridge(grid) << '\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
