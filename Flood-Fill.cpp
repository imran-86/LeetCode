#include<bits/stdc++.h>
using namespace std; 

 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        int xAxis[] = {-1, 0, 0, +1};
        int yAxis[] = {0, +1, -1, 0};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            image[r][c] = color;
            for(int i = 0; i < 4; i++){
                int dx = r + xAxis[i];
                int dy = c + yAxis[i];
                if(dx >= 0 && dx < row && dy >= 0 && dy < col 
                   && image[dx][dy] == originalColor){
                    q.push({dx, dy});
                }
            }
        }
       
        return image;
    }
};

void solve() {
    Solution sol;
    vector<vector<int>>image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr=1,sc=1,color=2;
    sol.floodFill(image,sr,sc,color);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}