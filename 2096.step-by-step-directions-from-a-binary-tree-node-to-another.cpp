/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
    TreeNode* lowestCommonAnsistor(TreeNode*root, int s, int d){
        if(root==NULL) return NULL;

        if(root->val==s or root->val==d) return root;

        TreeNode*leftChild = lowestCommonAnsistor(root->left, s, d);
        TreeNode*rightChild = lowestCommonAnsistor(root->right, s, d);

        if(leftChild==rightChild) return NULL;
        else if(leftChild==NULL) return rightChild;
        else if(rightChild==NULL) return leftChild;
        else return root;
    }
    bool pathFinder(TreeNode*root, int val, string &s){
        if(root==NULL) return false;
        if(root->val == val) return true;

        s.push_back('L');
        bool isLeft = pathFinder(root->left, val, s);
        if(isLeft) return true;
        s.pop_back();
        s.push_back('R');
        bool isRight = pathFinder(root->right,val, s);
        if(isRight) return true;
        s.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lca = lowestCommonAnsistor(root, startValue, destValue);
        string path_root_to_s = "", path_root_to_d = "";
        pathFinder(lca, startValue, path_root_to_s);
        pathFinder(lca, destValue, path_root_to_d);
        cout<<path_root_to_s<<","<<path_root_to_d<<endl;
        string path_s_to_root(path_root_to_s.size(), 'U');
        cout<<path_s_to_root<<endl;
        return path_s_to_root+path_root_to_d;
    }
};
// @lc code=end

