/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
		
		//Insert the interval in sorted order
        while(i<intervals.size() && newInterval[0]>intervals[i][0])
            i++;
        intervals.insert(intervals.begin()+i,newInterval);
        ans.push_back(intervals[0]);
        int j=0;
        for(int i = 1; i<intervals.size(); i++)
        {
		/*If end of previous inserted interval end value  is less than next Interval end value then only we have to consider it otherwise 
			discard and move ahead . If true check whether the current interval is overlapping with the next then merge and Push . If not just push interval in the ans vector. */
            if(ans[j][1] <= intervals[i][1])
            if(ans[j][1]>=intervals[i][0])
                ans[j][1] = intervals[i][1];
            else
            {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
        
    }
};
// @lc code=end

