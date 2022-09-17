/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */

// @lc code=start
class Solution {
public:
    int dp[101][101];
    int K;
    int fun(string s,int i,int k)
    {
        if(i==s.size())
        {
            if(k==K) return 0;
            else return 101;
        }    
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans = 101;
        for(int j=i;j<s.size();j++)
        {
            int c = 0;
            int l=i;
            int r=j;
            while(l<r)
                if(s[l++]!=s[r--])
                    c++;
            ans=min(ans,c+fun(s,j+1,k+1));
        }
        dp[i][k]=ans;
        return dp[i][k];

    }
    int palindromePartition(string s, int k) {
        if(s.size()==k)
            return 0;
        K=k;
        memset(dp,-1,sizeof(dp));
        return fun(s,0,0);
        
    }
};
// @lc code=end

