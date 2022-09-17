/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        int ans=0;
        bool ok=true;
        for(auto i:m)
        {
            if(i.second==1 and ok)
            {   
                ans++;
                ok=false;
            }
            else if(i.second>1)
            {
                if(i.second%2==1 and ok)
                {
                    ans+=i.second;
                    ok=false;
                }
                else
                    ans+=(i.second/2)*2;
            }
        }
        return ans;
    }
};
// @lc code=end

