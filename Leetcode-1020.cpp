#include<bits/stdc++.h>
using namespace std; 
class Solution {
    public:
    int countOne(vector<vector<int>>& grid,int r,int c,int row,int
        col,vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c] = true;
         int dx[] = {-1,0,0,1};
         int dy[] = {0,1,-1,0}; 
         int one = 1;
         int ans =0;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y + dy[i];
                if(newx>=0 and newx<row and newy>=0 and newy<col
                    and !visited[newx][newy] and grid[newx][newy]){
                    if(newx==0 or newx==row-1 or newy ==0 or newy
                        ==col-1){
                        ans =-1;
                    }else{
                        visited[newx][newy] = true;
                        q.push({newx,newy});
                        one++;
                    }
                }
            }
        }
        // cout<<r<<" "<<c<<'\n';
        // cout<<"One "<<one<<'\n';
        if(ans==-1){
            return 0;
        }
        else{
            return one;
        }
        return one;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j] and !visited[i][j]){

                    int one = countOne(grid,i,j,row,col,visited);
                    // cout<<"Grid "<<grid[i][j]<<' '<<one<<'\n';
                    if(one>0){
                        ans+=one;
                    }
                }
            }
        }
        // cout<<ans<<'\n';
        return ans;
    }
};
void solve() {
    Solution sol;
    vector<vector<int>> grid = {
    {0,1,1,0},
    {0,0,1,0},
    {0,0,1,0},
    {0,0,0,0}  
};
    
    
    sol.numEnclaves(grid);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
