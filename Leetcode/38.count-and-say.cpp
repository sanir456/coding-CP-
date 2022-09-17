/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        n--;
        while(n)
        {
            int j=ans.size();
            string temp="";
            int c=1;
            for(int i=1;i<j;i++)
            {
                if(ans[i]==ans[i-1])
                    c++;
                else
                {
                    temp=temp+to_string(c);
                    temp.push_back(ans[i-1]);
                    c=1;
                }
            }
            temp=temp+to_string(c);
            temp.push_back(ans[j-1]);
            n--;
            ans=temp;
        }
        return ans;
    }
};
// @lc code=end

