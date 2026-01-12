#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int l = 0;
        int r = size - 1;
        int ans = -1;
        while(l<r){
            int area = min(height[l],height[r])*(r-l);
            ans = max(ans,area);
            // cout<<l<<" "<<height[l]<<'\n';
            // cout<<r<<" "<<height[r]<<'\n';
            // cout<<area<<" "<<ans<<'\n';
            if(height[l]<height[r]){
                l++;
            }
            else if(height[r]<height[l]){
                r--;
            }
            else{
                if(l+1<size and r-1>l and height[l+1]>height[r-1]){
                   l++;
                }
                else{
                    r--;
                }
            }
        }
        cout<<ans<<'\n';
        return ans;

    }
};


void solve() {
    Solution sol;
    vector<int>numbers;
    numbers = {1,1};
    sol.maxArea(numbers);

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