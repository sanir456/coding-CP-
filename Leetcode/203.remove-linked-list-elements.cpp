/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head and head->val==val)
            head=head->next;
        if(!head)
            return head;
        ListNode* temp=head;
        ListNode* pre=temp;
        temp=temp->next;
        while(temp)
        {
            // cout<<temp->val<<" ";
            if(temp->val==val)
            {
                pre->next=temp->next;
            }
            else
                pre=pre->next;
            temp=temp->next;
            
        }
        return head;
    }
};
// @lc code=end

