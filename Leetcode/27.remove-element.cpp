/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = nums.size()-1;
        for(int i=0;i<=n;i++)
        {
            while(i<=n  and nums[i]==val)
                swap(nums[i],nums[n--]);
        }
        return n+1;
    }
};
// @lc code=end

