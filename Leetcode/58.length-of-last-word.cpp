/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        int i=0;
        while(i<n)
        {
            while(i<n and s[i]==' ')
                i++;
            if(i>=n)
                break;
            ans=0;
            while(i<n and s[i++]!=' ')
                ans++;
            while(i<n and s[i]==' ')
                i++;
        }
        return ans;
    }
};
// @lc code=end


