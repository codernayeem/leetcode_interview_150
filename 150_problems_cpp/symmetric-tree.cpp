#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b || a->val != b->val) 
            return false;

        if(!isMirror(a->left, b->right)) 
            return false;

        if(!isMirror(a->right, b->left)) 
            return false;
        
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};

int main(){
    Solution sol;

}