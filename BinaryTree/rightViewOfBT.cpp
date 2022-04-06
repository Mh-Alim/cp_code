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


// main code

// our main function which will return right view of a bt
vector<int> rightSideView(TreeNode* root) {

    // in ds we shall store right view of a bt
    vector<int> ds;
    if(root == NULL) return ds;
    rightView(root,ds,0);
    return ds;
}


// side function.. with the help of this we are inserting right of bt in ds
void rightView(TreeNode* root,vector<int> &ds,int level){
    if(root == NULL) return ;
    
    // this line tell is if we will visit level first time then we will insert that node in our ds
    if(level == ds.size()) ds.push_back(root->val);


    rightView(root->right,ds,level+1);
    rightView(root->left,ds,level+1);
}