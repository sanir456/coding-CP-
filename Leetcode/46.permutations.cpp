/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> c;
    int n;
    void fun(vector<bool>& v,int i,vector<int> item)
    {
        if(i==n)
        {
            ans.push_back(item);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(!v[j])
            {
                
                v[j]=true;
                item.push_back(c[j]);
                fun(v,i+1,item);
                v[j]=false;
                item.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        c=nums;
        n=c.size();
        vector<bool> v(n,false);
        vector<int> item;
        fun(v,0,item);
        return ans;
    }
};
// @lc code=end

