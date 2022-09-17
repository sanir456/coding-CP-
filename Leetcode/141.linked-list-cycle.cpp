/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* f=head;
        ListNode* s=head;
        while(f and s)
        {
            s=s->next;
            f=f->next;
            if(f)
                f=f->next;
            else
                return false;
            if(f==s)
                return true;
        }
        return false;
    }
};
// @lc code=end

