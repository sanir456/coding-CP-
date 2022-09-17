class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,int node,vector<int>& temp)
    {
        temp.push_back(node);
        if(node == graph.size()-1) ans.push_back(temp);
        else
        {
            for(int i:graph[node])
            {
                dfs(graph,i,temp);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        dfs(graph,0,temp);
        return ans;
    }
};