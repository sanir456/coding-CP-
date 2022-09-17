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

ll find(ll x, vector<ll>& parent)
{
	if (x == parent[x]) {
        return x;
    }
    return parent[x]=find(parent[x], parent);
}

set<pair<ll,ll>> fun(vector<vector<ll>>& edges,ll n,ll m)
{	
	vector<ll> par(n+1);
	set<pair<ll,ll>> ans;
	for(ll i=1;i<=n;i++)
		par[i]=i;
	
	for(auto e:edges)
	{
		ll x = find(e[0],par);
		ll y = find(e[1],par);
	
		if(x==y)
		{
			pair<ll,ll> p;
			if(e[0]<e[1])
				ans.insert({e[0],e[1]});
			else
				ans.insert({e[1],e[0]});
			if(ans.size()==m-n+1)
				break;
		}
		else
			par[x]=y;
	}
	return ans;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll> adj[n+1];
		vector<vector<ll>> edge;
		for(ll i=0;i<m;i++)
		{
			ll u,v;
			cin>>u>>v;
			if(u>v)
				swap(u,v);
			edge.push_back({u,v});
		}
		set<pair<ll,ll>> s= fun(edge,n,m);
		string ans="";
		for(auto i:edge)
		{
			pair<ll,ll> p = {i[0],i[1]};
			if(s.find(p)!=s.end())
				ans.push_back('1');
			else
				ans.push_back('0');
		}
		cout<<ans<<endl;
	}

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
