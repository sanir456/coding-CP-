/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,0),v(26);
        for(int i=0;i<s.size();i++)
        {
            if(f[s[i]-'a']==0)
                v[s[i]-'a']=i;
            f[s[i]-'a']++;
        }
        int ans = s.size();
        for(int i=0;i<26;i++)
            if(f[i]==1)
                ans=min(ans,v[i]);
        if(ans==s.size())
            return -1;
        return ans;
    }
};
// @lc code=end

