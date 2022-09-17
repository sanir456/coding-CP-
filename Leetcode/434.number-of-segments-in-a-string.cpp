/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int n=s.size();
        int i=0;
        while(i<n and s[i]==' ')
            i++;
        int ans=0;
        while(i<n)
        {
            while(i<n and s[i]!=' ')
                i++;
            ans++;
            
        while(i<n and s[i]==' ')
            i++;
        }
        return ans;
    }
};
// @lc code=end

