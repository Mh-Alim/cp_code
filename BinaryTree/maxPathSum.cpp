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
    int maxi = INT_MIN;

    // this function is just like height of a bt but with some modification

    int maxPath(TreeNode* root){
        if(root == NULL) return 0;

        // here we are taking max with 0 so that below test case can be handeled
        /*
                15
              /    \
            10      20
                   /  \
                -30   -15

        */

        int maxLt = max(0,maxPath(root->left));
        int maxRt = max(0,maxPath(root->right));

        // maxi is our ans
        maxi = max(maxi,maxLt+maxRt+root->val);
        
        return root->val+max(maxLt,maxRt);
    }
public:

// our main function 
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxi;
    }
    
};
