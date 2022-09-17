/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size();
      int i,j;
      for( i=n-1;i>0;i--)
      {
          if(nums[i-1]<nums[i])
            break;
      }  
      if(i!=0)
      {
          for(j=i;j<n;j++)
            if(nums[i-1]>=nums[j])
                break;
            j--;
        swap(nums[i-1],nums[j]);
      }
      sort(nums.begin()+i,nums.end());
    }
};
// @lc code=end

