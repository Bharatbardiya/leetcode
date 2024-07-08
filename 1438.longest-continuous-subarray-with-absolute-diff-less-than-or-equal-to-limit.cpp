/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start
class Solution {
public:
    bool safe(multiset<int>&st, int limit){
        if(st.size()==0) return true;
        int mini = *st.begin(), maxi = *(--st.end());
        return ((maxi-mini)<=limit);
    }
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int l = 0, r = 0, n = nums.size();
        int ans = 0;
        while(l<n and r<n and l<=r){
            if(safe(st, limit)){
                ans = max(ans, st.size());
                st.insert(nums[r]);
                r++;
            }
            else{
                auto it = st.find(nums[l]);
                st.erase(it);
                l++;
            }
        }
        if(safe(st,limit)){
            ans = max(ans,st.size());
        }
        return ans;
    }
};
// @lc code=end

