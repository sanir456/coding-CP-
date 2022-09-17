/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int ans=0;
        int cnt=0;
        for(int i=0;i<nums.size();)
        {
            cnt=1;
            i++;
            while(i<nums.size() and nums[i]==nums[i-1]+1)
            {
                cnt++;
                i++;
                while (i<nums.size() and nums[i]==nums[i-1])
                    i++;
                
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
// @lc code=end

