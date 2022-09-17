/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
      
        if(preorder.size()==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
   
        if(preorder.size()==1) return root;  
        int mid=0;
        while(mid<preorder.size() and preorder[0]!=inorder[mid]) mid++;

        if(mid==0)
            root->left=nullptr;
        else
        {
            vector<int> newPreLeft(preorder.begin()+1,preorder.begin()+mid+1);
            vector<int> newInLeft(inorder.begin(),inorder.begin()+mid);
            root->left=buildTree(newPreLeft,newInLeft);
        }    

        if(mid==preorder.size()-1)
            root->right=nullptr;
        else
        {
            vector<int> newPreRight(preorder.begin()+mid+1,preorder.end());
            vector<int> newInRight(inorder.begin()+mid+1,inorder.end());
            root->right=buildTree(newPreRight,newInRight);
        }
        return root;
    }
};
// @lc code=end

