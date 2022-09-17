class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> m1;
        map<string,int> m2;
        for(string s:words1)
            m1[s]++;
        for(string s:words2)
            m2[s]++;
        int ans = 0;
        if(m1.size()<m2.size())
        {
            for(auto i:m1)
                if(i.second==1 && m2.find(i.first)!=m2.end())
                {
                    if(m2[i.first]==1)
                        ans++;
                }
        }
        else
        {
            for(auto i:m2)
                if(i.second==1 && m1.find(i.first)!=m1.end())
                {
                    if(m1[i.first]==1)
                        ans++;
                }
        }
        return ans;
    }
};