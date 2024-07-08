/*
 * @lc app=leetcode id=2486 lang=cpp
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
class Solution {
public:
    int lcs(string &s, string &t, int i, int j){
        if(i==s.length() or j==t.length()) return 0;
        if(s[i]==t[j]) return 1+lcs(s, t, i+1, j+1);
        return lcs(s,t,i+1,j);
    }
    int appendCharacters(string s, string t) {
        int commonChar = lcs(s,t,0,0);
        return t.length()-commonChar;
    }
};
// @lc code=end

