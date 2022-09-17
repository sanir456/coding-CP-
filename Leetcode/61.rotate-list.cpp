/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* root=head;
        if(!root)
            return head;
        n=1;
        while(root->next)
        {
            root=root->next;
            n++;
        }
        k=k%n;
        root->next=head;
        k=n-k;
        k--;
        while (k--)
            head=head->next;
        root = head->next;
        head->next=NULL;
        return root;
        
    }
};
// @lc code=end

