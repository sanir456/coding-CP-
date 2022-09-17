/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int c = 0;
        int temp = digits[digits.size()-1]+1;
        if(temp>9)
        {
            temp=temp%10;
            c=1;
        }
        ans.push_back(temp);
        for(int i=digits.size()-2;i>=0;i--)
        {
            temp = digits[i]+c;
            if(temp>9)
            {
                temp=temp%10;
                c=1;
            }
            else
                c=0;
            ans.push_back(temp);
        }    
        if(c)
            ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

