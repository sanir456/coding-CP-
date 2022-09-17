/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        for(int i=0;i<s.size();i++)
            if(s[i]!='-')
                ans.push_back(toupper(s[i]));
        for(int i=ans.size()%k;i<ans.size();i=i+k)
        {
            if(i==0) continue;
            ans.insert(ans.begin()+i,'-');
            i++;
        }
        return ans;
    }
};
// @lc code=end

