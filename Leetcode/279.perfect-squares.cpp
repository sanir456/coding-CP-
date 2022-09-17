/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<=n;i++)
        {
            v.push_back(i*i);
        }
        int m = v.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,n+1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0) continue;
                else if(j==0) dp[i][j]=0;
                else
                {
                    if(v[i-1]<=j)
                    {
                        dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
                    }
                    else
                        dp[i][j]=dp[i-1][j];
                }    
            }
        }
        
        return dp[m][n];

    }
};
// @lc code=end

