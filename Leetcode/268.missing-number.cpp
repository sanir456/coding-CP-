/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = (n*(n+1))/2;
        for(auto i:nums)
            ans-=i;
        return ans;    
    }
};
// @lc code=end

