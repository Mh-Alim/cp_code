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



// main function
class Solution {
    void inorder(TreeNode* root ,int k, int &val,int &cnt){
        if(root == NULL) return ;
        inorder(root->left,k,val,cnt);
        cnt++;
        if(cnt==k){ 
            val = root->val;
        }
    
        inorder(root->right,k,val,cnt);
            
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = -1;
        int cnt = 0;
        inorder(root,k,val,cnt);
        return val;
    }
};