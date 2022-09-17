/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)
            return false;
        set<string> st;
        string temp = "";
        for(int i=0;i<k;i++)
            temp.push_back(s[i]);
        st.insert(temp);
        for(int i=k;i<s.size();i++)
        {
            temp.erase(temp.begin()+0);
            temp.push_back(s[i]);
            st.insert(temp);
        }
        if(st.size()==pow(2,k))
            return true;
        return false;
    }
};
// @lc code=end

