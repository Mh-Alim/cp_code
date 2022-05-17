#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<map>
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


// recursive way
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        TreeNode* a;
        if(val > root->val) a =  searchBST(root->right,val);
        if(val < root->val) a =  searchBST(root->left,val);
        
       return a;
    }
};


// iterative way



