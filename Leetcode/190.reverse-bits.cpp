/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            uint32_t temp = 0;
            if(n>>i&1)
                temp=1;
            temp=temp<<(31-i);
            ans+=temp;

        }
        return ans;
    }
    
};
// @lc code=end

