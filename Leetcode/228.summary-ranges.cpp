/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        if(nums.size()==1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        for(int i=0;i<nums.size();i++)
        {
            
            string temp = to_string(nums[i]);
            int k=i;
            while(i<nums.size()-1 and nums[i]+1==nums[i+1])
                i++;
            if(k!=i)
            {
                temp=temp+"->"+to_string(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
// @lc code=end

