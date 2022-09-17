/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
public:
    map<string,bool> m;
    bool isScramble(string a, string b) {
        string str = a+" "+b;
        if(m.find(str)!=m.end())
            return m[str];
        if(a.compare(b)==0) 
        {
            m[str]=true;
            return true;
        }
        if(a.size()<=1) 
        {
            
            m[str]=false;
            return false;
        }
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            if(((isScramble(a.substr(0,i),b.substr(n-i,i))) and 
                (isScramble(a.substr(i,n-i),b.substr(0,n-i))))
                or 
                ((isScramble(a.substr(0,i),b.substr(0,i))) and
                (isScramble(a.substr(i,n-i),b.substr(i,n-i)))))
                {
                    m[str]=true;
                    return true;
                }
        }       
        m[str]=false;
        return false;
    }
};
// @lc code=end

