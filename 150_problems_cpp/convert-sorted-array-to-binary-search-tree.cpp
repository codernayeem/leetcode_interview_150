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
    TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
        if(i > j) return NULL;
        if(i == j) return new TreeNode(nums[i]);
        int mid = i+(j-i)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, i, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, j);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;

        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};

int main(){
    Solution sol;

}