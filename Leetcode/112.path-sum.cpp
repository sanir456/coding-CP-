/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t->left==NULL and t->right==NULL and t->val==targetSum)
                    return true;
                if(t->left)
                {
                    t->left->val = t->val+t->left->val;
                    q.push(t->left);
                }
                if(t->right)
                {
                    t->right->val = t->val+t->right->val;
                    q.push(t->right);
                }
                
            }
        }
        return false;

    }
};
// @lc code=end

