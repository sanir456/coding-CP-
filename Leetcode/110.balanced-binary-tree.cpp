/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int height(TreeNode* root)
    {
        if(root)
            return 1+max(height(root->left),height(root->right));
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(isBalanced(root->left) and isBalanced(root->right))
        {
            if(abs(height(root->left)-height(root->right))<2)
                return true;

        }    
        return false;
    }
};
// @lc code=end

