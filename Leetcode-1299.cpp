#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_element = -1;
        for (int i = n - 1; i >= 0; i--) {
            int current_val = arr[i];
            arr[i] = max_element;
            max_element = max(max_element, current_val);
        }
        return arr;
    }
};
void solve() {
    Solution sol;
    vector<int>arr;
    arr= {17,18,5,4,6,1}; 
    
    
    sol.replaceElements(arr);
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
