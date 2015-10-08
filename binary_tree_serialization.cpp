/*
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.


Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.
*/

#include "header.h"

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res = to_string(root->val)+",";
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res += curr->left?to_string(curr->left->val):"#";
            res += ",";
            if(curr->left) q.push(curr->left);
            res += curr->right?to_string(curr->right->val):"#";
            res += ",";
            if(curr->right) q.push(curr->right);
        }
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        if(data.length() == 0) return NULL;
        stringstream ss(data);
        string temp;
        getline(ss, temp, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            string left, right;
            getline(ss, left, ',');
            getline(ss, right, ',');
            TreeNode* left_n = NULL, *right_n = NULL;
            if(left != "#"){
                left_n = new TreeNode(stoi(left));
                q.push(left_n);
            }
            if(right != "#"){
                right_n = new TreeNode(stoi(right));
                q.push(right_n);
            }
            curr->left=left_n;
            curr->right = right_n;
        }
        return root;
    }
};

int main(){
    vector<string> v = {"3","9","20","#","#","15","7"};
    TreeNode* root = create_tree(v);
    Solution s;
    string tree_str = s.serialize(root);
    cout<<tree_str<<endl;
    TreeNode* new_root = s.deserialize(tree_str);
    pre_order(new_root);
    return 0;
}
