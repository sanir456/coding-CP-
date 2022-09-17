/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
            mx=max(mx,nums[i]);
        int mx1=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mx)
                mx1=max(mx1,nums[i]);
        }
        int mx2=INT_MIN;
        bool ok=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mx1)
            {
                if(mx2<=nums[i])
                {
                    ok=false;
                    mx2=nums[i];

                }
            }
        }
        // cout<<mx<<" "<<mx1<<" "<<mx2;
        if(ok)
            return mx;
        else
            return mx2;
    }
};
// @lc code=end

