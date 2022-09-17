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
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> f(n+1,0);
		bool ok = false;
		
		vector<vector<ll>> v(n+1);
		vector<vector<ll>> e;
		for(ll i=0;i<n-1;i++)
		{
			ll l,r;
			cin>>l>>r;
			f[l]++;
			f[r]++;
			if(f[l]>2)
				ok=true;
			if(f[r]>2)
				ok=true;
			e.push_back({l,r});
			v[l].push_back(r);
			v[r].push_back(l);

		}
		if(ok)
		{
			cout<<-1<<endl;
			continue;
		} 	
		ll s;
		for(ll i=1;i<=n;i++)
		{
			if(v[i].size()==1)
			{
				s=i;
				break;
			}
		}	
		ok = true;
		map<pair<ll,ll>,ll> m;
		ll temp = n-1;
		while(temp--)
		{
			ll u;
			u = v[s][0];
			v[s].erase(v[s].begin());
			if(v[u].size()>0)
			{
				if(v[u][0]==s)
					v[u].erase(v[u].begin());
				else
					v[u].erase(v[u].begin()+1);
			}	
			if(ok)
			{

				m[{s,u}]=2;
				m[{u,s}]=2;
				ok=!ok;
			}
			else
			{
				m[{s,u}]=3;
				m[{u,s}]=3;
				ok=!ok;
			}
			
			s=u;
		}

		for(ll i=0;i<n-1;i++)
		{
			// cout<<e[i][0]<<" "<<e[i][1]<<endl;
			cout<<m[{e[i][0],e[i][1]}]<<" ";
		}
		cout<<endl;

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
