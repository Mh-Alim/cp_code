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


// checking if both tree are identical or not
bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL){
            if(p == q) return true;
            return false;
        }
        
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
}