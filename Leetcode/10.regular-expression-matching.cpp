/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
         if(p.empty()) return s.empty();
        bool ok = (!s.empty() and (p[0]==s[0] or p[0]=='.'));
        if(p.size()>=2 and p[1]=='*')
            return (isMatch(s,p.substr(2)) or (ok and isMatch(s.substr(1),p)));
        else
            return ok and isMatch(s.substr(1),p.substr(1));
    }
};
// @lc code=end

