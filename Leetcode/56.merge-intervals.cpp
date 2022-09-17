/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(),it.end());
        vector<vector<int>> ans;
        int n = it.size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp = it[i];
            int l = temp[0];
            int r = temp[1];
            while(i<n-1 &&  r >= it[i+1][0])
            {
                r = max(r,it[i+1][1]);
                i++;
            }
            temp[1]=r;
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

