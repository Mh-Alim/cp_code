
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




// main code starts from here 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root== NULL) return s;
        // Doing level order traversal 
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            TreeNode* currentNode = q.front();
            q.pop();
            if(currentNode == NULL) s.append("#,");
            else {
                s.append(to_string(currentNode->val)+',');
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
        
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        
        // level order traversal 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str == "#") curr->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(curr->left);
            }
            
            getline(s,str,',');
            if(str == "#") curr->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(curr->right);
            }
            
        }
        
        
        return root;
    }
};