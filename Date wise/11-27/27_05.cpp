class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        vector<bool> v(n,false);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='H')
            {
                if(i>0 && v[i-1])
                {
                    continue;
                }
                else if(i<n-1 && s[i+1]!='H')
                {
                    v[i+1]=true;
                    ans++;
                }
                else if(i>0 && s[i-1]!='H')
                {
                    v[i+1]=true;
                    ans++;
                }
                else
                {
                    ans=-1;
                    break;
                }
            }
        }
        return ans;
        
    }
};