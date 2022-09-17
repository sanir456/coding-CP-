/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=ma[i][j]-'0';
                else if(i==0)
                    dp[i][j]=dp[i][j-1]+ma[i][j]-'0';
                else if(j==0)
                    dp[i][j]=dp[i-1][j] + ma[i][j]-'0';
                else
                    dp[i][j]=ma[i][j]-'0' + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        if(dp[n-1][m-1]==0)
            return 0;
        int ans=1;
        for(int i=2;i<=min(m,n);i++)
        {
            bool ok=false;
            for(int x=i;x<=n and !ok;x++)
            {
                for(int y=i;y<=m and !ok;y++)
                {
                    if(x==i and y==i)
                    {
                        if(dp[x-1][y-1]==i*i)
                        {
                            ans=i;
                            ok=true;
                        }
                    }
                    else if(x==i)
                    {
                        if(dp[x-1][y-1]-dp[x-1][y-1-i]==i*i)
                        {
                            ans=i;
                            ok=true;
                        }
                    }
                    else if(y==i)
                    {
                        if(dp[x-1][y-1]-dp[x-1-i][y-1]==i*i)
                        {
                            ans=i;
                            ok=true;
                        }
                    }
                    else
                    {
                        if(dp[x-1][y-1]-dp[x-1-i][y-1]-dp[x-1][y-1-i]+dp[x-1-i][y-1-i]==i*i)
                        {
                            ans=i;
                            ok=true;
                        }
                    }
                }
                
            }
        
        }
        return ans*ans;
    }

};
// @lc code=end

