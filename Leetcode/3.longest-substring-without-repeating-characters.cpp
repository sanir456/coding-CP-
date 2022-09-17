/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
   
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char,int> v;
        int i=0;
        int j=0;
        int n=s.size();
        int cnt=0;
        while(i<n and j<n)
        {
            if(v[s[j]]==0)
            {
                v[s[j]]++;
                j++;
                ans=max(ans,j-i);
            }
            else
            {
                v[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end

