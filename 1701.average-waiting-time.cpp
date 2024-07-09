/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0, temp = customers[0][0];
        int n = customers.size();
        for(auto customer : customers){
            ans += customer[1];
            if(temp > customer[0]){
                ans += temp-customer[0];
                temp += customer[1];
            }
            else temp = customer[0]+customer[1];
        }
        return ans/n;
    }
};
// @lc code=end

