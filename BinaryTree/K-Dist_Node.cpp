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



// All nodes at a distance k in binary tree

class Solution {
    
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target){
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();q.pop();
            
            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
                
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> parent_track;
        
        markParents(root,parent_track,target);
        
        unordered_map<TreeNode*,bool> vis;
        
        queue<TreeNode*> q;
        
        q.push(target);
        
        vis[target] = true;
        
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(curr_level == k) break;
            curr_level++;
            
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left && !vis[current->left]) {
                    vis[current->left] = true;
                    
                    q.push(current->left);
                }
                if(current->right && !vis[current->right]) {
                    vis[current->right] = true;
                    
                    q.push(current->right);
                }
                
                if(parent_track[current] && !vis[parent_track[current]]){
                    q.push(parent_track[current]);
                    
                    vis[parent_track[current]] = true;
                }
            }
        }
        
        vector<int> res;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
        
    }
};