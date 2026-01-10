#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>u_map;
        for(auto x : nums){
            u_map[x]++;
        }
         vector<pair<int, int>> vec(u_map.begin(), u_map.end());
    sort(vec.begin(), vec.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second > b.second;  
         });
    vector<int>result;
   
    for(int i = 0; i < k && i < vec.size(); i++) {
        result.push_back(vec[i].first);
    }
    
    
    return result;
}
};



void solve() {
    Solution sol;
    vector<int>num;
    num = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    sol.topKFrequent(num , k);

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