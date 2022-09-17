/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)   return head;
        ListNode* low=nullptr;
        ListNode* high=nullptr;
        ListNode* l=nullptr;
        ListNode* h=nullptr;
        if(head->val<x)
        {
            low=head;
            l=low;
        }
        else
        {
            high=head;
            h=high;
        }
        while(head->next)
        {
            head=head->next;
            if(head->val<x)
            {
                if(low==nullptr)
                {
                    low=head;
                    l=low;
                }
                else
                {
                    low->next=head;
                    low=low->next;
                }
            }
            else
            {
                if(high==nullptr)
                {
                    high=head;
                    h=high;
                }
                else
                {
                    high->next=head;
                    high=high->next;
                }
            }
        }
        if(high)
            high->next=nullptr;
        if(l==nullptr)
            return h;
        else
        {
            low->next = h;
            return l;
        }
        
    }
};
// @lc code=end

