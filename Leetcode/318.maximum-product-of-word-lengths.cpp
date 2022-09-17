/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> m(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
            for(char c:words[i])
                m[i][c-'a']++;
        int ans = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool ok = true;
                for(int k=0;k<26 and ok;k++)
                {
                    if(m[i][k]>0 and m[j][k]>0)
                        ok=false;
                }
                if(ok)
                {
                    int m = words[i].size();
                    int n = words[j].size();
                    ans = max(ans,m*n);
                }
            }   
        } 
        return ans;
    }
};
// @lc code=end

