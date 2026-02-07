#include<bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    int countVisited(int n, vector<vector<int>>& adj, int node){
        queue<int> q;
        q.push(node);
        vector<bool> visited(n, false);  
        visited[node] = true; 
        int count = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto x : adj[front]){
                if(!visited[x]){
                    visited[x] = true;  
                    count++;
                    q.push(x);
                }
            }
        }
        // cout<<count<<'\n';
        if(count==n){
            return true;
        }
        return false;
    }

public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);  
        
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
        }
        
        for(int i = 0; i < n; i++){
            if(countVisited(n, adj, i)){
                cout<<i<<"\n";
                return i;
            }
        }
        
        return -1;
    }
};

void solve() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0,2},{1,3},{1,2}};
    
    sol.findChampion(n, edges);
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
