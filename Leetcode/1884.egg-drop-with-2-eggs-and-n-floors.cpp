/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution {
public:
    int dp[3][1001];
    int solve(int e,int f)
    {
        if(dp[e][f]!=-1)
            return dp[e][f];
        if(f==1 or f==0 or e==1)
        {
            dp[e][f]=f;
           return f;
        }
        
        int ans = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            ans = min(ans,1+max(solve(e-1,k-1),solve(e,f-k)));
        }
        dp[e][f]=ans;
        return ans;
    }

    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
};
// @lc code=end

