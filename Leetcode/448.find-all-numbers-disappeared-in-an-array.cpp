/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
// @lc code=end

