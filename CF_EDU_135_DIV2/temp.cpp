#include<bits/stdc++.h>
using namespace std;

int maxFlow(vector<vector<pair<int,int>>>& adj,int node)
{
	cout<<"size"<<" "<<adj[node].size()<<
    if(adj[node].size()==0)
        return 100005;
    

    int ans = 0;
	
    for(int i=0;i<adj[node].size();i++)
    {
           cout<<ans<<endl;
        int flow = maxFlow(adj,adj[node][i].first);
        // cout<<p.first<<" "<<p.second<<endl;
        
    	ans += min(adj[node][i].second,flow);
    }
 
    return ans;
}

int main()
{
	
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	
	
    int node;
    cin>>node;
    int root;
    cin>>root;
    int numCon;
    cin>>numCon;
    int charCon;
    cin>>charCon;

    vector<vector<pair<int,int>>> adj(node);

    while(numCon--)
    {
        int u,v,flow;
        cin>>u>>v>>flow;
        adj[u].push_back(make_pair(v,flow));
    }
    cout<<"sani"<<endl;
    int answer = maxFlow(adj,root);
   	
    cout<<answer<<endl;
    return 0;
}