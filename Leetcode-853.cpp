#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int carFleet(int target, vector<int>& position, 
        vector<int>& speed) {
        int n = position.size();
        // sort(position.rbegin(),position.rend());
        vector<pair<int,double>>steps(n);
        for(int i=0;i<n;i++){
            int x = target - position[i];
            steps[i].first=position[i];
            steps[i].second=double(x)/double(speed[i]);
        }
        sort(steps.rbegin(),steps.rend());
        // for(int i=0;i<n;i++){
        //     cout<<steps[i].first<<" "<<steps[i].second<<'\n';
        // }
        double maxTime = steps[0].second;
        int ans = 1;
        for(int i=0;i<n;i++){
             if(steps[i].second>maxTime){
                ans++;
                maxTime=steps[i].second;
             }
        }
        // cout<<ans<<'\n';
        return ans;
    }
};
void solve() {
    Solution sol;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;    
    sol.carFleet(target,position,speed);
    
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
