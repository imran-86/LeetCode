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
public:
    void inorder(TreeNode* root,vector<int>&ans){
           if(!root){
            return;
           }
           inorder(root->left,ans);
           ans.push_back(root->val);
           inorder(root->right,ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
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
    vector<int> nodes1 = {5,3,6,2,4,-1,-1,1};
    int k = 5;  
    TreeNode* root1 = helper.buildTree(nodes1);
    // helper.printTree(root1);
    solution.kthSmallest(root1,k);
    // helper.printTree(root1);
    helper.deleteTree(root1);
    return 0;
}