#include<iostream>
#include<stack>
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





/* In this i am finding whether tree is balaced bt or not */
// tc - O(n2); brute force 


class Solution {

    // this function will give me height of a tree;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    }

public:

    // This function will give me whether a tree is bbt or not
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh,rh;
        

        // we are calling this function for each node;
        // we are checking each node height here and if this will return false then we directly return false otherwise true;
        if(root->left == NULL)  lh = 0;
        else  lh = height(root->left);
        
        if(root->right == NULL)  rh = 0;
        else  rh = height(root->right);
        
        
        if(abs(lh-rh)>1) return false;
        bool rt = isBalanced(root->right);
        bool lt = isBalanced(root->left);
        if(!rt || !lt) return false;
        return true;
    }



};

// TC = o(N) 
// optimize tc and code also
// as we know in height it is going in all node and taking max of of lh and rh and here we do one step to check there whether they are balance bt or not


// Our main function
int height(TreeNode* root){
    if(root==NULL) return 0;

    int lh = height(root->left);
    if(lh == -1) return -1;

    int rh = height(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root) {
    if(height(root) == -1) return false;
    return true;
}