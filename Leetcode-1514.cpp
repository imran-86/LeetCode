#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
        vector<double>& succProb, int start_node, int end_node) {
        vector<double>dist(n,0.0);
        vector<vector<pair<int,double>>>adj(n);
        int edges_size = edges.size();
        for(int i=0;i<edges_size;i++){
           int u = edges[i][0];
           int v = edges[i][1];
           double prob = succProb[i];
           adj[u].push_back({v,prob});
           adj[v].push_back({u,prob});
        }
      
        priority_queue<pair<double,int>>pq;
        pq.push({1.000,start_node});
        dist[start_node] = 1.000;
        while(!pq.empty()){
            auto [x,y] = pq.top();
            // cout<<x<<" "<<y<<"\n";
            pq.pop();
            if(x<dist[y]){
                continue;
            }
            for(auto [v,w] : adj[y]){
                if(dist[y]*w>dist[v]){
                    dist[v]= dist[y]*w;
                    pq.push({dist[v],v});
                }
            }

        }
        return dist[end_node];
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>edges = {{0,1},{1,2},{0,2}};
    int n =3;
    int start_node = 0;
    int end_node = 2;
    vector<double> succProb = {0.5,0.5,0.3};
    
    sol.maxProbability(n,edges,succProb,start_node,end_node);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
