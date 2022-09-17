/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_set<int> st;
        int ans=nums[0];
        st.insert(nums[0]);
        int sum=nums[0];
        while(i<n and j<n)
        {
            if(st.size()==(j-i+1))
            {
                j++;
                ans=max(ans,sum);
                if(j<n)
                {
                    st.insert(nums[j]);
                    sum+=nums[j];
                }
            }
            else
            {
                sum-=nums[i];
                st.erase(nums[i]);
                st.insert(nums[j]);
                i++;
            }
            
            
        }
        return max(ans,sum);
    }
};
// @lc code=end

