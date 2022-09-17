/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size();
        int s = 0;
        for(auto i: nums)
            s+=i;
        vector<vector<int>> dp(n+1,vector<int>(s+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
                if(i>0)
                {
                    if(nums[i-1]<=j)
                        dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
               
            }
        }
        int ans=0;
        for(int i=0;i<=s;i++)
        {

            if(s+target==2*i)
                ans += dp[n][i]; 
        }
        return ans;
        

    }
};
// @lc code=end

