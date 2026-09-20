#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
     int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};
        visited[sr][sc] = true;
        while(!q.empty()){
            auto [x,y] = q.front();
            // cout<<"Parent "<<x<<" "<<y<<'\n';
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx>=0 and newx<row and newy>=0 and newy<col
                    and !visited[newx][newy] and image[x][y]==image
                    [newx][newy]){
                    visited[newx][newy] = true;
                    q.push({newx,newy});
                    // image[newx][newy]=color;
                    // cout<<"Child "<<newx<<" "<<newy<<'\n';
                }

            }

        }
        for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
         if(visited[i][j]){
            image[i][j]=color;
         }
    }
}
        return image;

    }
};
void solve() {
    Solution sol;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, color = 2;
    
    sol.floodFill(image, sr, sc, color);
    
    for(int i = 0; i < (int)image.size(); i++){
        for(int j = 0; j < (int)image[0].size(); j++){
            cout << image[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
