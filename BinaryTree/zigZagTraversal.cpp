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


// this travesal is modification of level order traversal 


 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // in ans i will store the final answer
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // level order traversal 
        
        queue<TreeNode*> q;
        q.push(root);
        
        //  variable l which will tell us whether we have to push the level in same way or in opposite way
        int l = 0;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);
            }
            
            // pushing level in opposite direction
            if(l%2 !=0){
                vector<int> lev;
                for(int i=level.size()-1;i>=0;i--){
                    lev.push_back(level[i]);
                }
                ans.push_back(lev);
            }
            
            //pushing level
            else ans.push_back(level);
            
            l++;
            
        }
        
        return ans;
    }