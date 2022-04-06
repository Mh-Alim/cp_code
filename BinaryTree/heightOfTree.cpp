#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//  Definition for a binary tree node. 
 struct TreeNode {     int val;
    TreeNode *left;     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive way height of a tree

int maxDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        int left = maxDepth(root->left);
        int rigt = maxDepth(root->right);
        return 1+max(left,rigt);
}

// level order traversal -- height of a tree

int maxDepth1(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // traversing on queue
        
        while(!q.empty()){
            int size = q.size();
            
            // traversing level wise
            for(int i=0;i<size;i++){
                
                TreeNode* node = q.front();
                q.pop();
                if(node->left!= NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
            }
            ans++;
        }
        
        return ans;
    }