/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int ans=0;
        while(i<s.size() and j<g.size())
        {

            while(i<s.size() and s[i]<g[j])
                i++;
            if(i==s.size())
                break;
            ans++;
            j++;
            i++;
        }
        return ans;
    }
};
// @lc code=end

