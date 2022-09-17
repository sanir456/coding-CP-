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
        if(left==right)
            return head;
        ListNode* root = head;
        
        left--;
        right--;
        ListNode* l = nullptr;
        while(left-- and right-- and root->next)
        {
            l=root;
            root=root->next;
        }
        ListNode* r = root;
        ListNode* p = root;
        ListNode* c = root->next;
        ListNode* n = nullptr;
        if(c->next)
            n = c->next;
        while(right--)
        {
            c->next=p;
            p=c;
            c=n;
            if(n)
                n=n->next;
        }
        r->next=c;
        if(l==nullptr)
            head=p;
        else
            l->next=p;
        return head;

    }
};
// @lc code=end

