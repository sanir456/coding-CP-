/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multi_set;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int  n=nums.size();
        multi_set s;
        ll ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=s.order_of_key(nums[i]);
            s.insert(2*1ll*nums[i]);
        }
        return ans;
    }
};
// @lc code=end

