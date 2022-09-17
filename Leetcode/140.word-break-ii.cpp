/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    map<string,string> m;
    vector<string> ans;
    vector<string> w;
    void fun(string s,string t)
    {
        if(s.size()==0)
        {
            ans.push_back(t);
            return;
        }
        if(m.find(s)!=m.end())
        {
            if(t.size()==0)
                t=m[s];
            else
                t=t+" "+m[s];
            ans.push_back(t);
        }
        for(string q:w)
        {
            int n = q.size(); 
            
            if(s.size()>=n and s.substr(0,n).compare(q)==0)
            {
                string temp;
                if(t.size()==0)
                    temp=q;
                else
                    temp=t+" "+q;
                
                fun(s.substr(n),temp);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        w=wordDict;
        fun(s,"");
        return ans;
    }
};
// @lc code=end

