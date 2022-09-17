/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num1) {
        string ans="";
        long long int num = num1;
        if(num<0)
            num = 4294967296+num;

        vector<char> hex{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(num==0)
            return "0";
        while(num)
        {
            int temp = num%16;
            ans+=hex[temp];
            num=num/16;
        }
        reverse(ans.begin(),ans.end());
        // if(n)
        // {
        //     int k = 8-ans.size();

        // }
        return ans;
    }
};
// @lc code=end

