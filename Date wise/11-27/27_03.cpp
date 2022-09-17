class Solution {
public:
    int minCost(vector<int>& r, vector<int>& h, vector<int>& row, vector<int>& col) {
        int ans=0;
        if(r[0]==h[0] && r[1]==h[1])
            return 0;
        else
        {
            if(r[0]>h[0])
                for(int i=r[0]-1;i>=h[0];i--)
                    ans += row[i];
            else
            {
                for(int i=r[0]+1;i<=h[0];i++)
                    ans += row[i];
            }
            if(r[1]>h[1])
                for(int i=r[1]-1;i>=h[1];i--)
                    ans += col[i];
            else
            {
                for(int i=r[1]+1;i<=h[1];i++)
                    ans += col[i];
            }
        }
        return ans;
    }
};