/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> m(26,0);
        for(int i=0;i<s.size();i++)
        {
            m[s[i]-'a']++;
            m[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            if(m[i]!=0)
                return false;
        return true;
    }
};
// @lc code=end

