#include <bits/stdc++.h>
using namespace std;

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        targetSum -= root->val;
        if(!root->left && !root->right) {
            if(targetSum == 0) return true;
            else return false;
        }
        if(hasPathSum(root->left, targetSum)){
            return true;
        }
        if(hasPathSum(root->right, targetSum)){
            return true;
        }
        return false;
    }
};


int main(){
    Solution sol;
}