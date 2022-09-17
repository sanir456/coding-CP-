/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int h = 0; h < 12; h++)
        for (int m = 0; m < 60; m++)
            if (bitset<10>(h << 6 | m).count() == num)
                ans.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return ans;
    }
};
// @lc code=end

