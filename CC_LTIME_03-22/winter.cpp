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

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	


	ll n,m,q,u,v;
    cin>>n>>m>>q;
    vector<vector<ll>> edge(n+1);
    for(ll i=0;i<m;i++) 
    {
	    cin>>u>>v;
	    edge[u].pb(v);
	    edge[v].pb(u);
	}
	map<ll,ll> mp;
	queue<ll> qu;
	ll t,a;
  	while(q--) {
    	cin>>t>>a;
	    if(t==3) 
	    {
	      if(mp[a]==1) cout<<"YES\n";
	      else cout<<"NO\n";
	    }
	    else if(t==1) 
	    {
	      if(mp[a]==0) qu.push(a);
	      mp[a]=1;
	    }
	    else 
	    {
	        for(ll i=0;i<a && !qu.empty();i++) 
	        {
	        	ll k=qu.size();
	        	while(k--) 
	        	{
		           ll w=qu.front();
		           qu.pop();
		           for(auto i:edge[w]) 
		           {
		            	if(mp[i]==0) 
		            	{
		                	mp[i]=1;
		                	qu.push(i);
		                }
		           }
	            }
	        }
	    }
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
