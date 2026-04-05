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
       TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
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
            cout << "null" << endl;
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        cout << "[";
        bool first = true;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(!first) cout << ",";
            first = false;
            
            if(node){
                cout << node->val;
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null";
            }
        }
        cout << "]" << endl;
    }
    
    
    void printVector(vector<int>& vec) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ",";
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
    vector<int> nodes1 = {4,2,7,1,3,6,9};  
    TreeNode* root1 = helper.buildTree(nodes1);
    
    TreeNode* invert = solution.invertTree(r);
    helper.printTree(invert);
    helper.deleteTree(root1);

    
    
    return 0;
}