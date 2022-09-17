/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto i:nums1)
            s.insert(i);
        set<int> ans;
        for(auto i:nums2)
            if(s.find(i)!=s.end())
                ans.insert(i);
        vector<int> a;
        for(auto i:ans)
            a.push_back(i);
        return a;

    }
};
// @lc code=end

