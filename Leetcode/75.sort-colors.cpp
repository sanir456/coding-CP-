/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]==0 and i<=k)
                swap(nums[i++],nums[k]);
           
        }
        for(int k=0;k<nums.size();k++)
        {
            while(nums[k]==2 and k<j)
                swap(nums[j--],nums[k]);
           
        }
        return;
    }
};
// @lc code=end

