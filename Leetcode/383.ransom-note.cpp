/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26,0);
        for(char c:magazine)
            m[c-'a']++;
        for(char c:ransomNote)
            if(m[c-'a']==0)
                return false;
            else    
                m[c-'a']--;
        return true;
    }

};
// @lc code=end

