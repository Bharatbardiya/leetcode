/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        int ops = 0;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second > 1){
                ops += (it->second-1);
                mp[it->first+1] += (it->second-1);
            }
        }
        return ops;
    }
};
// @lc code=end

