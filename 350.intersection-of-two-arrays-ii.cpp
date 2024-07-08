/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int MAX_LEN = 1001
        vector<vector<int>>matrix(MAX_LEN, vector<int>(2));

        for(auto x : nums1) matrix[x][0]++;
        for(auto x : nums2) matrix[x][1]++;
        
        vector<int>ans;
        for(int i = 0; i<MAX_LEN; i++){
            int t = min(matrix[i][0], matrix[i][1]);
            for(int j = 0; j<t; j++) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

