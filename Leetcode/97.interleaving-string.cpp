/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        if(n+m!=k)
            return false;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==j and i==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=dp[i][j-1] and s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j] and s1[i-1]==s3[i+j-1];
                else
                    dp[i][j]=(dp[i][j-1] and s2[j-1]==s3[i+j-1]) or (dp[i][j]=dp[i-1][j] and s1[i-1]==s3[i+j-1]);
            }
        }
        return dp[n][m];
        
       
    }
};
// @lc code=end

