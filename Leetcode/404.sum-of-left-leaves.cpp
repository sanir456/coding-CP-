/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root,TreeNode* p)
    {
        if(root->left==nullptr and root->right==nullptr and p->left==root)
                return root->val;
        int ans1=0;
        if(root->left)
            ans1=fun(root->left,root);
        int ans2=0;
        if(root->right)
            ans2=fun(root->right,root);
        return ans1+ans2;
    }
    int sumOfLeftLeaves(TreeNode* root) {
    return fun(root,root);
            
        
    }
};
// @lc code=end

