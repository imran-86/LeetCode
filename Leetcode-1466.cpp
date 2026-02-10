#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int, int>>> adj(n);
        
        for(auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1});  
            adj[v].push_back({u, 0});  
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        
        int reversals = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto [neighbor, needReverse] : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    reversals += needReverse; 
                    q.push(neighbor);
                    // cout<<neighbor<<" "<<needReverse<<'\n';
                }
            }
        }
        
        return reversals;
    }
};
void solve() {
    Solution sol;
    int n = 6;
    vector<vector<int>>connections;
    connections = {{1,0},{1,4}};
    sol.minReorder(n,connections);
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}