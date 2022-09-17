/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1;i<=n/2;i++)
        {
            if(n%i!=0)
                continue;
            string temp = s.substr(0,i);
            bool ok = true;
            for(int j=i;j<n and ok;j=j+i)
            {
                if(s.substr(j,i).compare(temp)!=0)
                    ok=false;
            }
            if(ok)
                return true;
        }
        return false;
    }
};
// @lc code=end

