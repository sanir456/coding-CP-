/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                dp[i]=nums[i-1];
            else{
                dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

