#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        vector<int>result;
        for(int i=0;i<size;i++){
            int cur = numbers[i];
            int req = target - cur;
            int l = i+1;
            int r = size-1; 
            while(l<=r){
                int mid = (l+r)/2;
                if(numbers[mid]==req){
                    result.push_back(i+1);
                    result.push_back(mid+1);
                    return result;
                }
                else if(numbers[mid]>req){
                    r = mid -1 ;
                }
                else{
                    l = mid + 1;
                }
            }
        }
       
        return result;
    }
};



void solve() {
    Solution sol;
    vector<int>numbers;
    numbers = {2,3,4};
    int target = 6;
   
    sol.twoSum(numbers,target);

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