#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
     int src, int dst, int k) {
         priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &flight : flights){
            int u = flight[0];
            int v = flight[1];
            int val = flight[2];
            adj[u].push_back({v,val});
        }
        vector<int>stops(n,INT_MAX);
        while(!pq.empty()){
            auto [cost,uStop] = pq.top();
            pq.pop();
            int u = uStop.first;
            int stop = uStop.second;
            if(u==dst){
                return cost;
            }
            if(stop>k){
                continue;
            }
            if(stop>=stops[u]){
                continue;
            }
            stops[u] = stop;
            for(auto [v,val] : adj[u]){
                pq.push({(cost + val), {v, stop + 1}});
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<" ";
        //     cout<<dist[i]<<'\n';
        // }cout<<'\n';
        return -1;
    }
};
void solve() {
    Solution sol;
    int n = 3;
    vector<vector<int>> flights = 
    {{0,1,100},
    {1,2,100},
    {0,2,500}};
    int  src = 0;
    int dst = 2;
    int k = 0;
   int ans = sol.findCheapestPrice(n,flights,src,dst,k);
   cout<<ans<<'\n';
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
