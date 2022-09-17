/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        int ans=1;
        vector<vector<int>> dir{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int> p=q.front();
                if(p.first==n-1 and p.second==n-1)
                    return ans;
                q.pop();
                for(auto d:dir)
                {
                    int nr=p.first+d[0];
                    int nc=p.second+d[1];
                    if(nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]==0 and vis[nr][nc]==0)
                    {
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end

