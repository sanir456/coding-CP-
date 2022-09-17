/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool fun(TreeNode* left,TreeNode* right)
    {
        if(left==NULL and right==NULL)
            return true;
        else if(left and right)
        {
            if(left->val==right->val)
            {
                if(!fun(left->left,right->right)) return false;
                if(!fun(left->right,right->left)) return false;
                return true;
            }
            return false;
        }   
        return false;     
    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }
};
// @lc code=end

