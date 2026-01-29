#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
  public : 
  void bfs(int node,unordered_map<int,vector<int>>&adj,
    unordered_map<int,bool>&visited){
    queue<int>q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto x :adj[front]){
            if(!visited[x]){
                // cout<<front<<" "<<x<<'\n';
            visited[x]=true;
             q.push(x);
            }
        }
    }
  }
public:
    int findCircleNum(vector<vector<int>>&isConnected) {
        unordered_map<int,vector<int>>adj;
        int row = isConnected.size();
        int col = isConnected[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        unordered_map<int,bool>visited;
        
        int count=0;
        // cout<<row<<'\n';
        for(int i=1;i<=row;i++){
             if(!visited[i]){
                // cout<<i<<" "<<visited[i]<<"\n";
                count++;
                bfs(i,adj,visited);
             }
        }
        // cout<<count<<'\n';
        return row==1?1:count;
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>isConnected;
    isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<sol.findCircleNum(isConnected)<<'\n';

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int t=1;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;

}