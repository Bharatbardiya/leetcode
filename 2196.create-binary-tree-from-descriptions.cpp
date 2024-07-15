/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>st;
        map<int,int>temp;
        
        for(auto v : descriptions){
            int p = v[0], ch = v[1], isLeft = v[2];
            temp[ch]++;
            TreeNode *prNode = NULL, *chNode = NULL;

            auto it_p = st.find(p);
            auto it_ch = st.find(ch);

            if(it_p!=st.end()){
                prNode = it_p->second;
            } else {
                prNode = new TreeNode(p);
                st[p] = prNode;
            }

            if(it_ch!=st.end()){
                chNode = it_ch->second;
            } else {
                chNode = new TreeNode(ch);
                st[ch] = chNode;
            }

            if(isLeft){
                prNode->left = chNode;
            } else {
                prNode->right = chNode;
            }
        }
        int head;
        for(auto v : descriptions){
            if(temp.find(v[0])==temp.end()){
                head = v[0];
            }
        }
        auto itr = st.find(head);
        return itr->second;
    }
};
// @lc code=end

