#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      
        for(int i = 0; i < 9; i++) {
            vector<bool> seen(9, false);  
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';  
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        
        for(int j = 0; j < 9; j++) {
            vector<bool> seen(9, false);
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        
        for(int box = 0; box < 9; box++) {
            vector<bool> seen(9, false);
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    char c = board[startRow + i][startCol + j];
                    if(c == '.') continue;
                    
                    int num = c - '1';
                    if(seen[num]) return false;
                    seen[num] = true;
                }
            }
        }
        
        return true;
    }
};

void solve() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    bool isValid = sol.isValidSudoku(board);
    cout << (isValid ? "Valid" : "Invalid") << endl;
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