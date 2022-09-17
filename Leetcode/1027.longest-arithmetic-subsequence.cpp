/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int m=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end())+1;
        vector<vector<int>> dp(n,vector<int>(2*m+1,1));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d =m+nums[j]-nums[i];
                dp[j][d]=1+dp[i][d];
                ans=max(dp[j][d],ans);
            }
        }       
        return ans;
    }
};
// @lc code=end

