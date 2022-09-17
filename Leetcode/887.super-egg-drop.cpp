/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int dp[101][10001];
    int solve(int e,int f)
    {
        if(dp[e][f]!=-1)
            return dp[e][f];
        if(e==1 or f<=1) 
        {
            dp[e][f]=f;
            return f;
        }
        int ans=10001;
        int l=1,r=f;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int left = solve(e-1,mid-1);
            int right = solve(e,f-mid);
            ans  = min(ans,1+max(left,right));
            if(left<right)
                l=mid+1;
            else
                r=mid-1;
        }
        return dp[e][f]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};
// @lc code=end

