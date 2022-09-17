/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        int l=1;
        int st=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                l=2;
                st=i;
            }
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k=j+i-1;
                if(dp[j+1][k-1] and s[j]==s[k])
                {
                    dp[j][k]=true;
                    st=j;
                    l=i;
                }
            }
        }
        return s.substr(st,l);
    }
};
// @lc code=end

