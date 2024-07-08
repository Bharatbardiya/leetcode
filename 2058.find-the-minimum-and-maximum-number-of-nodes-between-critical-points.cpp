/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool helper(int x, int y, int z){
        bool first = ((x<y) and (z<y));
        bool second = ((x>y) and (z>y));
        return first or second;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>criticalPoints;
        int i = 0;
        ListNode *curr = head, *prev = NULL;
        vector<int>ans = {-1,-1};

        if(curr==NULL or curr->next==NULL) return ans;
        while(curr->next!=NULL){
            if(prev!=NULL and helper(prev->val, curr->val, curr->next->val)){
                criticalPoints.push_back(i);
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if(criticalPoints.size()<2) return ans;
        int maxi = criticalPoints.back()-criticalPoints[0];
        ans = {maxi,maxi};
        for(int i = 0; i<criticalPoints.size()-1; i++){
            ans[0] = min(ans[0], criticalPoints[i+1]-criticalPoints[i]);
        }
        return ans;
    }
};
// @lc code=end

