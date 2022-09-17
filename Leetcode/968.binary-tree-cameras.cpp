/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    int ans=0;
    int fun(TreeNode* root)
    {
        if(root==nullptr)   return 0;
        int left=fun(root->left);
        int right=fun(root->right);
        if(left==-1 or right==-1)
        {
            ans++;
            return 1;
        }
        if(left==1 or right==1)
        {
            return 0;
        }
        return -1;

    }
    
    int minCameraCover(TreeNode* root) {
       return (fun(root)==-1)?ans+1:ans;
        
    }
};
// @lc code=end

