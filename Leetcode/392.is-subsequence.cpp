/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0,j=0;
        while(i<n and j<m)
        {
            if(s[i]==t[j])
                i++;
            j++;
        }
        return i==n;
    }
};
// @lc code=end

