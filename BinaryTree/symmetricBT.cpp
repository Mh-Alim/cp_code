#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
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


// simultaneously two recursion 
class Solution {
public:

    // main function
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL) return true;
        
        return isSymmetricHelp(root->left,root->right);

        
    }
    
    //side function
    
    bool isSymmetricHelp(TreeNode* left,TreeNode* right){
        if(right == NULL || left == NULL){
            return right == left;
        }
        
        if(left->val != right->val) return false;
        
        return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
    }
};