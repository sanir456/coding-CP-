/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        bool flag = false;
        while(head->next and head->val==head->next->val)
        {
            head=head->next;
            flag=true;
        }
        if(flag)
        {
            head=head->next;
            head = deleteDuplicates(head);
        }
        else
            head->next = deleteDuplicates(head->next); 
        return head;
    }
};
// @lc code=end

