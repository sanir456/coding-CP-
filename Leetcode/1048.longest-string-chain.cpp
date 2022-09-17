/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    static bool comp(string& i,string& j)
    {
        if(i.size()<j.size())
            return true;
        return false;

    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        int ans=1;
        sort(words.begin(),words.end(),comp);
        for(string s:words)
        {
            dp[s]=1;
            for(int i=0;i<s.size();i++)
            {
                string t=s.substr(0,i)+s.substr(i+1);
                if(dp.find(t)!=dp.end())
                {
                    dp[s]=max(dp[s],dp[t]+1);
                    ans=max(ans,dp[s]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

