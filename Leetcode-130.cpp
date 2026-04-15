#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void bfs(vector<vector<bool>>&visited,
        vector<vector<char>>& board,int r,int c,
        vector<pair<int,int>>&ans){
          visited[r][c]=true;
          queue<pair<int,int>>q;
          q.push({r,c});
          ans.push_back({r,c});
          int row = board.size();
          int col = board[0].size();
          int dx[]={-1,0,1,0};
          int dy[]={0,1,0,-1};
          while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newr = x + dx[i];
                int newc = y + dy[i];
                if(newc>=0 and newc<col and newr>=0 and 
                    newr<row and !visited[newr][newc]
                    and board[newr][newc]=='O'){
                      ans.push_back({newr,newc});
                      visited[newr][newc]=true;
                      q.push({newr,newc});

                }
            }
          }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>>ans;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 or i==n-1 or j==0 or j==m-1){
                if(!visited[i][j] and board[i][j]=='O'){
                    bfs(visited,board,i,j,ans);
                }
            }
        }
       }
       sort(ans.begin(), ans.end());
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' and 
                !binary_search(ans.begin(), ans.end(), make_pair(i,j))){
                board[i][j]='X';
            }
        }
       }
       
    }
};

void solution() {
    Solution sol;
    vector<vector<char>>board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'O','X','O','X'},
        {'X','O','X','X'}
    };
    
    sol.solve(board);
}

int main() {
    int t = 1;
    while(t--) {
        solution();
    }
    return 0;
}
