/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>friends(n,0);
        for(auto i = 0; i<n; i++) friends[i] = i+1;

        int del = 0, i = 0;
        while(del!=n-1){
            int size = friends.size();
            i = (i+k-1)%size;
            friends.erase(friends.begin()+i);
            i = (i)%(size-1);
            del++;
        }
        return friends[0];
    }
};
// @lc code=end

