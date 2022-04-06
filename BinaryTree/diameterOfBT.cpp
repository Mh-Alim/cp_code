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



class Solution {
    // this function is giving height of a tree;

     int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    }

    // for each node we are finding max of (right hight + left height)
    // because max of rh+lh is our diameter of binary tree
    // tc - O(N2);
    // in this check function we are maximizing our diameter
    int check(TreeNode* root,int &maxi){
        if(root == NULL) return true;
        int lh,rh;
        

        if(root->left == NULL)  lh = 0;
        else  lh = height(root->left);
        
        if(root->right == NULL)  rh = 0;
        else  rh = height(root->right);
        maxi = max(maxi,rh+lh);

        
        int rt = check(root->right,maxi);
        int lt = check(root->left,maxi);
        return true;
    }
public:

    // this function giving diameter of tree;
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = INT_MIN;
        check(root,maxi);
        return maxi;
    }

};

// now we are optimizing time complexity 
// tc -- O(N);
// we are again calculating diameter from height of a binary tree

class Solution1 {
    int maxi = INT_MIN;
     int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
   
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int a = height(root);
        return maxi;
    }
};

