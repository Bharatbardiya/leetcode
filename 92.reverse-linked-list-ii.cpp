/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *Left = NULL, *Right = NULL;
        ListNode *curr = head;
        while(curr != NULL){
            if(curr->val==left) Left = curr;
            if(curr->val==right) Right = curr;
            curr = curr->next;
        }

        
    }
};
// @lc code=end

