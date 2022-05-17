
#include<iostream>
#include<sstream>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<map>
#include<string>
#include<string.h>
#include<math.h>
#define max(a ,b) (((a) > (b)) ? (a) : (b))


using namespace std;


//  Definition for a binary tree node. 
 struct TreeNode {     int val;
    TreeNode *left;     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Recursive approach

class Solution {
public:
    
    // side function
    
    void flatTree(TreeNode* root,TreeNode* &prev)
    {
        if(root == NULL) return ;
        flatTree(root->right,prev);
        flatTree(root->left,prev);
        
        root->right = prev;
        prev = root;
        root->left = NULL;
    }
    
   
    
    // main function
    
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        flatTree(root,prev);
    }
};


// Iterative approach 

class Solution {
public:
    
    // main function
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            
            if(!st.empty()) node->right = st.top();
            node->left = NULL;
        }
    }
};