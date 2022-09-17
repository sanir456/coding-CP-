/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 and vis[i][j]==0)
                {
                    // cout<<i<<" "<<j<<endl;
                    bool ok=true;
                    if(grid1[i][j]==0)
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
                            if(nr>=0 and nr<n and nc>=0 and nc<m and grid2[nr][nc]==1 and vis[nr][nc]==0)
                            {
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                                if(grid1[nr][nc]==0)
                                    ok=false;
                            }
                        }
                    }
                    if(ok) 
                        ans++;
                    
                }
            }
        }
        return ans;
    }
};
// @lc code=end

