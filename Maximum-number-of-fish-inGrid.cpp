#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    int countFish(int row,int col, vector<vector<int>>&grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c,false));  
        int count = grid[row][col];

        int xAxis[] = {-1,0,0,+1};
        int yAxis[] = {0,+1,-1,0};
         visited[row][col] = true;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int newr = x + xAxis[i];
                int newc = y + yAxis[i];
        if(newr<r and newr>=0 and newc<c and newc>=0 and
         grid[newr][newc]>0 and !visited[newr][newc]){
                  visited[newr][newc] = true;
                  q.push({newr,newc});
                  count+=grid[newr][newc];
                }
            }

            
        }
        // cout<<count<<'\n';
        return count;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int maxFish = 0;
        for(int i = 0; i < r; i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]>0){
                   int ans = countFish(i,j,grid);
                   maxFish = max(maxFish,ans);

                }
            }
        }
        // cout<<maxFish<<"\n";
        return maxFish;
    }
};

void solve() {
    Solution sol;
    vector<vector<int>>grid =
    {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    
    sol.findMaxFish(grid);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
