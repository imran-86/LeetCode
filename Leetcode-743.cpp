#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &x:times){
            int u =x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
        }
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            for(auto [v,w] : adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxTime = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxTime=max(maxTime,dist[i]);
        }
        // cout<<maxTime<<'\n';
        return maxTime;

    }
};
void solve() {
    Solution sol;
    vector<vector<int>>times = {{2,1,1},{2,3,1},{3,4,1}};
    int k =2;
    int n =4;
    
    sol.networkDelayTime(times,n,k);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
