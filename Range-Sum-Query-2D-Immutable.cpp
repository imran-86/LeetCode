#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class NumMatrix {
public:
    vector<vector<int>>sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};
void solve() {
    Solution sol;
    vector<vector<int>>grid;
    grid = {
  {2,1,1},
  {0,1,1},
  {1,0,1}
};
    cout<<sol.NumMatrix(grid)<<'\n';

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