/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            int c=0;
            for(int j=0;j<32;j++)
                if(i>>j&1)
                    c++;
            ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end

