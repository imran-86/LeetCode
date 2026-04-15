#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<vector<int>>ans;
    vector<int>path;
public:
    void dfs(vector<vector<int>>&graph,vector<int>&path,
        vector<vector<int>>&ans,int source,int destination){
        path.push_back(source);
        if(source==destination){
            ans.push_back(path);
            // for(auto y: path){
            //     cout<<y<<" ";
            // }cout<<'\n';
        }
        for(auto x : graph[source]){
            dfs(graph,path,ans,x,destination);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>&graph) {
        int dest = graph.size()-1;
        dfs(graph,path,ans,0,dest);
        return ans;
    }
};

void solve() {
    Solution sol;
    vector<vector<int>>graph = {
        {1,2},
        {3},
        {3},
        {}
    };
    
    sol.allPathsSourceTarget(graph);
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
