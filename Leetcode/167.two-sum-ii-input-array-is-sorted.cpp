/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r)
        {
            if(numbers[l]+numbers[r]==target)
                return {l+1,r+1};
            else if(numbers[l]+numbers[r]>target)   
                r--;
            else
                l++;
        }
        return {};
    }
};
// @lc code=end

