#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
    public :
    vector<string> generateChildren(string s){
          
          vector<string>generatedChildren;
          for(int i=0;i<4;i++){
            string preS = s;
            preS[i] = (preS[i] - '0' + 1) % 10 + '0';
            generatedChildren.push_back(preS);

            preS = s;
            preS[i] = (preS[i] - '0' - 1 + 10) % 10 + '0';
            generatedChildren.push_back(preS);
          }
          return generatedChildren;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool>visited;
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000")) return -1;
        visited["0000"]=true;
        queue<pair<string,int>>q;
        int turn = 0;
        q.push({"0000",turn});
        if(target=="0000"){
            return 0;
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            vector<string>childs;
            childs=(generateChildren(x));
            if(x==target){
                    return y;
                }
                
            for(auto child : childs){
                 if(!visited[child] and !dead.count(child)){
                    q.push({child,y+1});
                    visited[child]=true;
                }
            }
        }
        return -1;

    }

};
void solve() {
    Solution sol;
     vector<string>deadends;
     deadends = {"0201","0101","0102","1212","2002"};
     string target = "0202";
    cout<<sol.openLock(deadends,target)<<'\n';

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