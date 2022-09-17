/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            while(l<r and !(tolower(s[l])>='a' and tolower(s[l]<='z')) and !(tolower(s[l])>='0' and tolower(s[l]<='9')))
                l++;
            while(l<r and !(tolower(s[r])>='a' and tolower(s[r]<='z')) and !(tolower(s[r])>='0' and tolower(s[r]<='9')))
                r--;  
            cout<<l<<" "<<r<<endl;  
            if(tolower(s[l++])!=tolower(s[r--]))
                return false;         
        }
        return true;
    }
};
// @lc code=end


