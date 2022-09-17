/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int lo=0;
        int hi = matrix.size()-1;
        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            if(matrix[mid][0]>target)
                hi = mid;
            else
                lo = mid+1;
        }
        if(lo==(matrix.size()-1))
        {
            if(matrix[lo][0]>target)
                lo--;
        }
        else
            lo--;
        cout<<lo;
        if(lo<0)
            return false;
        int l = 0;
        int r = matrix[0].size()-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            cout<<mid<<" ";
            if(matrix[lo][mid]==target)
                return true;
            else if(matrix[lo][mid]<target)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};
// @lc code=end

