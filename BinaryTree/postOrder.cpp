#include<vector> 
#include<iostream>
#include<stack>

using namespace std;

// two stack solution


//   Definition for a binary tree node.
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
    vector<int> postorderTraversal(TreeNode* root) {

        // this ans will store final preorder of binary tree
        vector<int> ans;
        if(root == NULL) return ans;

        
        stack<TreeNode*> st1,st2;

        
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL){
                st1.push(node->left);
            }
            if(node->right != NULL){
                st1.push(node->right);
            }
        }
        
        while(!st2.empty()){
            int node = st2.top()->val;
            st2.pop();
            ans.push_back(node);
        }
        
        return ans;
    }
};