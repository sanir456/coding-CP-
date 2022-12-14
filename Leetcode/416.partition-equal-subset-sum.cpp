/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;i++)
            s+=nums[i];
        if(s%2==1)
            return false;
        s = s/2;    
        vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else{
                    if(nums[i-1]<=j)
                        dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
           
        }
        return dp[n][s];
    }
};
// @lc code=end

