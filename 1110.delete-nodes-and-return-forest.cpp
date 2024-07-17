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
    TreeNode* helper(TreeNode*root, vector<TreeNode*>&ans, unordered_set<int>&st){
        if(root==NULL) return NULL;
        if(st.find(root->val)!=st.end()){
            TreeNode*left = helper(root->left, ans, st);
            TreeNode*right = helper(root->right, ans, st);
            if(left!=NULL) ans.push_back(left);
            if(right!=NULL) ans.push_back(right);
            delete root;
            return NULL;
        }
        
        root->left = helper(root->left, ans, st);
        root->right = helper(root->right, ans, st);
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>st;
        for(auto x : to_delete) st.insert(x);

        root = helper(root, ans, st);
        if(root!=NULL) ans.push_back(root);

        return ans;
    }
};