/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    int fun(int n)
    {
        int ans = 0;
        while(n)
        {
            ans+=(n%10)*(n%10);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int s=n;
        
        int f=n;
        while(f!=1 and s!=1)
        {
            s=fun(s);
            f=fun(f);
            if(fun(s)!=1)
                f=fun(f);
            else
                return true;
            if(f==s)
                return false;
        }
        return true;
    }
};
// @lc code=end

