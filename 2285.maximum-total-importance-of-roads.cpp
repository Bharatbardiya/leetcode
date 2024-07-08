/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>hash(n);
        for(auto road : roads){
            int u = road[0], v = road[1];
            hash[u]++; hash[v]++;
        }
        // for(auto x : hash) cout<<x<<",";
        // cout<<endl;
        sort(hash.begin(), hash.end(), greater<int>());
        // for(auto x : hash) cout<<x<<",";
        // cout<<endl;
        long long ans = 0;
        for(auto x : hash){
            long long t = x;
            ans += (t*n);
            n--;
        }
        return ans;
    }
};
// @lc code=end

