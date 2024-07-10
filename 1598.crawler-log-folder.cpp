/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;

        for(auto log : logs){
            if(log.substr(0,2)==".."){
                if(st.size()>0) st.pop();
            }
            else if(log.substr(0,1)!="."){
                st.push(log);
            }
        }
        return st.size();
    }
};
// @lc code=end

