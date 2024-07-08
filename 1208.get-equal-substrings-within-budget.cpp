/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int>diff(n);
        for(int i = 0; i<n; i++){
            diff[i] = abs(s[i]-t[i]);
        }

        int i = 0, j = 0;
        int cost = 0;
        int ans = 0;
        while(j>=i and i<n and j<n){
            cost+=diff[j];
            j++;
            if(cost <= maxCost){
                ans = max(ans, j-i);
            }
            else{
                while(i<=j and cost>maxCost and i<n){
                    cost -= diff[i];
                    i++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

