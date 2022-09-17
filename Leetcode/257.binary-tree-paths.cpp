/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)
            return ans;
        if(root->left or root->right)
        {
            vector<string> ans1 = binaryTreePaths(root->left);
            vector<string> ans2 = binaryTreePaths(root->right);
            for(auto p:ans1)
            {
                p = to_string(root->val)+"->"+p;
                ans.push_back(p);
            }
            for(auto p:ans2)
            {
                p = to_string(root->val)+"->"+p;
                ans.push_back(p);
            }
        }
        else
        {
            ans.push_back(to_string(root->val));
        }
        return ans;
    }
};
// @lc code=end

