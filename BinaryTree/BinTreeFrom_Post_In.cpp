
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


// main code starts from here.........

class Solution {
public:

    // main function 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return buildTree_In_Post(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }

    // side function
    
    TreeNode* buildTree_In_Post(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int,int>& mp)
    {
        if(ps>pe || is>ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[root->val];
        
        int numsLeft = inRoot - is;
        
        root->left = buildTree_In_Post(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mp);
        
        root->right = buildTree_In_Post(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mp);
        
        return root;


    }
};