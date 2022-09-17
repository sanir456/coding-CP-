/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int cnd;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                cnd=nums[i];
                cnt=1;
            }
            else
            {
                if(cnd==nums[i])
                    cnt++;
                else 
                    cnt--;
            }
        }
        
        return cnd;
        
    }
};
// @lc code=end

