/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution {
public:

    string reverseParentheses(string s) {

        // brute force solution start
        stack<char>st;
        int i = 0, n = s.length();
        while(i<n){
            if(s[i]==')'){
                string temp = "";
                while(st.size()>0 and st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                if(st.size()>0) st.pop();
                for(auto x : temp) st.push(x);
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // brute force solution end
    }
};
// @lc code=end

