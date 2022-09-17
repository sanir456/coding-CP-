/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else 
                    if(str1[i-1]==str2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=n;
        int j=m;
        string ans="";
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else
                {
                    ans.push_back(str2[j-1]);
                    j--;
                }
        }
        while(i>0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }


        reverse(ans.begin(),ans.end());
        return ans;

    }
};
// @lc code=end

