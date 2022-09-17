/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    // cout<<i<<" "<<j<<endl;
                    bool ok=true;
                    int t=1;
                    if(i==0 or i==n-1 or j==0 or j==m-1)
                        ok=false;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty())
                    {
                        pair<int,int> p=q.front();
                        q.pop();
                      
                        for(auto d:dir)
                        {
                            int nr=p.first+d[0];
                            int nc=p.second+d[1];
                            if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and vis[nr][nc]==0)
                            {
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                                if(nr==0 or nr==n-1 or nc==0 or nc==m-1)
                                    ok=false;
                                t++;
                            }
                        }
                    }
                    if(ok) ans+=t;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

