/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n<0)
        {
            if(n%2==0)
            {
                double ans=myPow(x,n/2);
                return ans*ans;
            }
            else return myPow(x,n+1)/x;
        }
        else
        {
            if(n%2==0)
            {
                double ans=myPow(x,n/2);
                return ans*ans;
            }
            else return myPow(x,n-1)*x;
        }
    }
};
// @lc code=end

