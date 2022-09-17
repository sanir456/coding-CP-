/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                
                if(i==0 or j==0)
                    dp[i][j]=0;
                else
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else    
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
// @lc code=end

