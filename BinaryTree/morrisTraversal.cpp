
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




// our main code starts from here
// inorder 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        // morrish traversal 
        
        vector<int> inorder;
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        
        
        
        return inorder;
    }
};


// preorder

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        // morrish traversal 
        
        vector<int> inorder;
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;
                if(prev->right == NULL){
                    prev->right = curr;
                    inorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        
        
        
        return inorder;
    }
};


