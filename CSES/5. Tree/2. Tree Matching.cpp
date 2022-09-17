#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
#define endl '\n'

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int ans=0;
void dfs(int node,int par,vector<int> adj[],vector<int>& vis)
{
	for(auto i:adj[node])
	{
		if(i==par) continue;
		dfs(i,node,adj,vis);
		if(!vis[i] and !vis[node])
		{
			ans++;
			vis[i]=1;
			vis[node]=1;
		}
	}
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int i=1*4/3-27%9+100*0.5-(4>3?1:2); 
	cout<<i<<endl;
	int n;
	// cin>>n;
	vector<int> adj[n+1];
	for(int i=1;i<n;i++)
	{
		int u,v;
		// cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	dfs(1,0,adj,vis);
	cout<<ans<<endl;
	

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
