/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> c;
    int t;
    void fun(vector<int>& s,int n,int i,int sum)
    {
        if(sum==t)
        {
            ans.push_back(s);
            return;
        }
        if(sum>t)
            return;
        for(int j=i;j<n;j++)
        {
            if(j!=i and c[j]==c[j-1])
                continue;
                
            sum+=c[j];
            s.push_back(c[j]);
            fun(s,n,j+1,sum);
            sum-=c[j];
            s.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        t=target;
        c=candidates;
        sort(c.begin(),c.end());
        vector<int> s;
        fun(s,c.size(),0,0);
        return ans;
    }
};
// @lc code=end

