/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w=1;
        int l=area;
        int mn = l-w;

        for(int i=2;i*i<=area;i++)
        {
            if(area%i!=0) continue;
            int w_new=i;
            int l_new=area/i;
            if(l_new-w_new<mn)
            {
                mn=l_new-w_new;
                l=l_new;
                w=w_new;
            }
        }
        return {l,w};
    }
};
// @lc code=end

