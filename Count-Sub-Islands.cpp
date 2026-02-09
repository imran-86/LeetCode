#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    bool bfs(int row, int col, vector<vector<int>>& grid2,
            vector<vector<int>>& grid1,
            vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({row, col});
        int r = grid2.size();
        int c = grid2[0].size();
        int xAxis[] = {-1, 0, 0, +1};
        int yAxis[] = {0, +1, -1, 0};
        
        visited[row][col] = true;
        bool isSubIsland = true;
        
        
        if(grid1[row][col] == 0) {
            isSubIsland = false;
        }
        
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int newr = x + xAxis[i];
                int newc = y + yAxis[i];
                
                if(newr >= 0 && newr < r && newc >= 0 && newc < c
                   && !visited[newr][newc] && grid2[newr][newc] == 1){
                    
                    visited[newr][newc] = true;
                    q.push({newr, newc});
                    if(grid1[newr][newc] == 0) {
                        isSubIsland = false; 
                    }
                }
            }
        }
        
        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                       vector<vector<int>>& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();
        int subIslands = 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));  
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid2[i][j] == 1 && !visited[i][j]){
                    if(bfs(i, j, grid2, grid1, visited)){
                        subIslands++;
                    }
                }
            }
        }
        
        cout << subIslands << "\n";
        return subIslands;
    }
};

void solve() {
    Solution sol;
    vector<vector<int>> grid1 = {
        {1,1,1,1,0,0},
        {1,1,0,1,0,0},
        {1,0,0,1,1,1},
        {1,1,1,0,0,1},
        {1,1,1,1,1,0},
        {1,0,1,0,1,0},
        {0,1,1,1,0,1},
        {1,0,0,0,1,1},
        {1,0,0,0,1,0},
        {1,1,1,1,1,0}
    };
    vector<vector<int>> grid2 = {
        {1,1,1,1,0,1},
        {0,0,1,0,1,0},
        {1,1,1,1,1,1},
        {0,1,1,1,1,1},
        {1,1,1,0,1,0},
        {0,1,1,1,1,1},
        {1,1,0,1,1,1},
        {1,0,0,1,0,1},
        {1,1,1,1,1,1},
        {1,0,0,1,0,0}
    };
    
    sol.countSubIslands(grid1, grid2);
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}