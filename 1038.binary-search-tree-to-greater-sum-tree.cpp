/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int last = 0;
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->right);
        last += root->val;
        root->val = last;
        helper(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};
// @lc code=end

