/*
 * @lc app=leetcode id=2139 lang=cpp
 *
 * [2139] Minimum Moves to Reach Target Score
 */

// @lc code=start
class Solution {
public:
    int fun(int target, int maxDoubles, int curr){
        if(target==curr){
            return 0;
        }
        int t1 = curr+1, t2 = curr*2;
        int mini = 1+fun(target, maxDoubles, t1);
        if(maxDoubles>0 and t2<=target){
            mini = min(mini,1+fun(target, maxDoubles-1, t2));
        }
        return mini;
    }
    int minMoves(int target, int maxDoubles) {
        int curr = 1;
        return fun(target, maxDoubles, curr);
    }
};
// @lc code=end

