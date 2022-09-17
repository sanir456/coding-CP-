/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j and i==0)
                    continue;
                if(i!=j and i==0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];   
                else if(i!=j and j==0)
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];  
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

