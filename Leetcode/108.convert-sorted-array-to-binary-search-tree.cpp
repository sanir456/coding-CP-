/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* fun(vector<int> num,int l,int r)
    {
        if(l>r)
            return NULL;
        // if(l==r)
        // {
        //     TreeNode* ans;
        //     ans->val = num[l];
        //     ans->left=NULL;
        //     ans->right=NULL;
        //     return ans;
        // }
        int mid = l + (r-l)/2;
        TreeNode* ans= new TreeNode(num[mid]);
        ans->left=fun(num,l,mid-1);
        ans->right=fun(num,mid+1,r);
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);

    }
};
// @lc code=end

