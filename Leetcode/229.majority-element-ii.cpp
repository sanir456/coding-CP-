/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnd1;
        int cnd2;
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            
            if(cnd1==nums[i]) cnt1++;
            else if(cnd2==nums[i]) cnt2++;
            else if(cnt1==0)
            {
                cnd1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                cnd2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cnd1) cnt1++;
            else if(nums[i]==cnd2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(cnd1);
        if(cnt2>n/3) ans.push_back(cnd2);
        return ans;
    }
};
// @lc code=end

