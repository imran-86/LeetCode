#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();
            int r = pos.first;
            int c = pos.second;

            if (cost > dist[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) 
                    {
                        continue;
                    }

                int w = (grid[r][c] == k + 1) ? 0 : 1;

                if (dist[r][c] + w < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + w;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>grid ={
        {1,2},
        {4,3},
        };
    
    sol.minCost(grid);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
