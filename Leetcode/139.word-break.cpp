/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    map<string,bool> m;
    vector<string> w;
    bool fun(string s)
    {
        cout<<s<<endl;
        if(s.size()==0)
            return true;
        if(m.find(s)!=m.end())
            return m[s];
        int ans = false;
        for(string q:w)
        {
            int n = q.size();
           
            cout<<s.substr(0,n).compare(q)<<endl;
               
            if(s.size()>=n and s.substr(0,n).compare(q)==0)
            {
                ans = ans or fun(s.substr(n));
            }
        }
        m[s]=ans;
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string s:wordDict)
            m[s]=true;
        w=wordDict;
        return fun(s);
    }
};
// @lc code=end

