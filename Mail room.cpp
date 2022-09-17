#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int ans=0;
int solve(vector<vector<int>> adj,int node,int parent,vector<int>& vis)
{
	vis[node]=1;
	bool need = false;
	bool notneed = false;
	for(auto i:adj[node])
	{
		if(i==parent or vis[i]==1) continue;
		int res = solve(adj,i,node,vis);
		if(res==-1)
			need=true;
		if(res==1)
			notneed = true;
	}
	if(need)
	{
		ans++;
		return 1;
	}
	if(notneed)
		return 0;
	else 
		return -1;
}

void stop(int *p,int *q)
{
	static int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	printf("%d",++*q++);
}

int main(){
	init_code();
	
	int a[]={2,4,6,8},i;
	for(int i=0;i<3;i++)
	{
		stop(&i,&a[i]);
	}
	
	
	
	// int n,m;
	// cin>>n>>m;
	// vector<int> v(2*m);
	// for(int i=0;i<2*m;i++)
	// 	cin>>v[i];
	// vector<vector<int>> adj(n+1);
	// for(int i=0;i<m;i++)
	// {
	// 	adj[v[i]].push_back(v[i+m]);
	// 	adj[v[i+m]].push_back(v[i]);
	// }
	// vector<int> vis(n+1,0);
	// for(int i=1;i<=n;i++)
	// {
	// 	if(vis[i]==0)
	// 		solve(adj,i,i,vis);
	// }
	// cout<<ans<<endl;
	// return 0;
}


// 9 8
// 1 2 3 4 7 6 3 8
// 2 3 4 5 6 3 8 9