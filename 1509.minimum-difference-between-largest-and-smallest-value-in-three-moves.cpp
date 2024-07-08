/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0;
        int j = n-4;
        int ans = INT_MAX;
        while(j<n){
            ans = min(ans, nums[j]-nums[i]);
            i++; j++;
        }
        return ans;
    }
};
// @lc code=end

