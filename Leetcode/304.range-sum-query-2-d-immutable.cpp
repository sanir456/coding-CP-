/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        preSum=matrix;
        int n=preSum.size();
        int m=preSum[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                    continue;
                if(i==0)
                    preSum[i][j]+=preSum[i][j-1];
                else if(j==0)
                    preSum[i][j]+=preSum[i-1][j];
                else
                    preSum[i][j]=preSum[i][j]+preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1];
                
            }
         
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = preSum[row2][col2];
        if(row1==0 and col1==0 )
            return ans;
        if(row1==0)
            ans-=preSum[row2][col1-1];
        else if(col1==0)
            ans-=preSum[row1-1][col2];
        else
            ans=ans-preSum[row2][col1-1]-preSum[row1-1][col2]+preSum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

