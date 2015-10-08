/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.


Example
If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].

    20
   /  \
  8   22
 / \
4   12
*/

#include "header.h"

TreeNode* getNext(TreeNode* curr){
    if(!root) return NULL;
    TreeNode* res;
    if(curr->right)
        for(res = curr->right;res->left;res = res->left);
    else{
         
    }
    return res;
}

vector<int> searchRange(TreeNode* root, int k1, int k2) {
    vector<int> res;
    return res;
}

int main(){
    vector<string> v = {"20", "8", "22", "4", "12"};
    TreeNode* root = create_tree(v);
    print_vector<int>(searchRange(root, 10, 22));
    return 0;
}
