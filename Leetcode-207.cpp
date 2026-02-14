#include<bits/stdc++.h>
using namespace std; 

class Solution {
    public : 
    void dfs(int node , vector<vector<int>>&adj,
        vector<int>&color,bool &cycle){
         color[node]=1;
         for(auto next : adj[node]){
            if(color[next]==0){
                dfs(next,adj,color,cycle);
            }
            else if(color[next]==1){
                cycle = true;
            }
         }
         color[node]=2;
    }
public:
    bool canFinish(int numCourses,
        vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int size = prerequisites.size();
        for(int i=0;i<size;i++){
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adj[x].push_back(y);
        }
        vector<int>color(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(color[i]==0){
                bool cycle = false;
                dfs(i,adj,color,cycle);
                // cout<<i<<" "<<cycle<<'\n';
                if(cycle){
                    return false;
                }
            }
        }
        return true;
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>prerequisites;
   int numCourses = 2;
    prerequisites = {{1,0}};

    cout<<sol.canFinish(numCourses,prerequisites)<<'\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}