#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    bool isOk = true;
public:
    int check(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = 1+check(root->left);
        int right = 1+check(root->right);
        if(abs(left-right)>1){
            isOk=false;
        }
        return max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        check(root);
        // cout<<isOk<<'\n';
        return isOk;
    }
};
    

class TreeHelper {
public:
    TreeNode* buildTree(vector<int>& nodes) {
        if (nodes.empty() || nodes[0] ==-1) return nullptr;
        TreeNode* root = new TreeNode(nodes[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != -1) {
                curr->left = new TreeNode(nodes[i]);
                q.push(curr->left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != -1) {
                curr->right = new TreeNode(nodes[i]);
                q.push(curr->right);
            }
            i++;

        }
        
        return root;
    }
     void printTree(TreeNode* root) {
        if(root == nullptr){
            // cout << "null" << endl;
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        cout << "[";
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                cout << node->val<<" ";
                q.push(node->left);
                q.push(node->right);
            } 
        }
        cout << "]" << endl;
    }
    
    
    
    
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
int main() {
    TreeHelper helper;
    Solution solution;
    vector<int> nodes1 = {1,2,2,3,3,-1,-1,4,4};  
    TreeNode* root1 = helper.buildTree(nodes1);
     solution.isBalanced(root1);
    // helper.printTree(result);
    helper.deleteTree(root1);
    return 0;
}