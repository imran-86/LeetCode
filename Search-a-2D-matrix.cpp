#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // cout<<matrix.size()<<'\n';
        int  i = 0, j = matrix[0].size()-1;
        while (i<matrix.size() && j>=0){
            if (matrix[i][j] == target){
                return true;
            } 
            else if (target>matrix[i][j])
            {
                cout<<matrix[i][j]<<'\n';
                i = i + 1;
            } 
            else if (target<matrix[i][j]){
                cout<<matrix[i][j]<<'\n';
                j = j - 1;
            } 

        }
        return false;
    }
};

void solve() {
    Solution sol;
     vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    cout<<sol.searchMatrix(matrix,target)<<'\n';

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