/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        for(int i=1;i<n;i++)
        {
            if(i==1)
                dp[i]=nums[i-1];
            else{
                dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
            }
        }

        vector<int> dp1(n+1,0);
        for(int i=2;i<=n;i++)
        {
            if(i==2)
                dp1[i]=nums[i-1];
            else{
                dp1[i]=max(dp1[i-2]+nums[i-1],dp1[i-1]);
            }
        }
        return max(dp[n-1],dp1[n]);
    }
};
// @lc code=end

