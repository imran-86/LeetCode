#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, 
        int node1, int node2) {
        int n = edges.size();
        vector<int>adj(n+10);
        for(int i = 0;i<n;i++){
            adj[i]=edges[i];
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(node1);
        visited[node1]=true;
        int distance = 0;
        vector<int>pathDistance(n,-1);
        pathDistance[node1]=distance;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            int x = adj[front];
            if(x!=-1 and !visited[x]){
                 q.push(x);
                 distance++;
                 pathDistance[x]=distance;
                 visited[x]=true;
            }
           
        }
        vector<bool>visited1(n+10,false);
        q.push(node2);
        visited1[node2]=true;
        distance = 0;
        vector<int>pathDistance1(n,-1);
        pathDistance1[node2]=distance;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            int x = adj[front];
            if(x!=-1 and !visited1[x]){
                 q.push(x);
                 distance++;
                 pathDistance1[x]=distance;
                 visited1[x]=true;
            }
           
        }
        int minDist = INT_MAX;
        int result = -1;
        
        for(int i = 0; i < n; i++) {
            if(pathDistance[i] != -1 && pathDistance1[i] != -1) {
                int maxDist = max(pathDistance[i],pathDistance1[i]);
                if(maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }
       // cout<<result<<'\n';
        return result;
    }
};
void solve() {
    Solution sol;
    vector<int>edges;
    edges = {1,2,-1};
    int node1 = 0,node2=2;
    cout<<sol.closestMeetingNode(edges,node1,node2)<<'\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}