/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head, *next = NULL;
        ListNode *Curr = NULL, *Prev=NULL;
        while(curr!=NULL){
            if(curr->val==0){
                Prev = Curr;
                if(Curr!=NULL){
                    Curr->next = curr;
                    Curr = Curr->next;
                }else{
                    Curr = curr;
                }
                curr = curr->next;
            }
            else{
                next = curr->next;
                Curr->val += curr->val;
                delete curr;
                curr = next;
            }
        }
        delete Curr;
        Prev->next = NULL;
        return head;
    }
};
// @lc code=end

