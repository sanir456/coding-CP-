/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        while(l<r)
        {
            while(l<r and st.find(tolower(s[l]))==st.end())
                l++;
                
            while(l<r and st.find(tolower(s[r]))==st.end())
                r--;
            if(l<r)
                swap(s[l],s[r]);
            l++;
            r--;
        }  
        return s;
    }
};
// @lc code=end

