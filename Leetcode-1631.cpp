#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
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
                 int currentDiff = abs(heights[nr][nc]-heights[r][c]);
                 int newEffort = max(cost,currentDiff);

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
        cout<<dist[m-1][n-1]<<'\n';
        return dist[m-1][n-1];
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>heights = 
    {{1,2,2},
     {3,8,2},
     {5,3,5}};
    sol.minimumEffortPath(heights);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
