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
void print(queue<ll> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

ll mod = 1e9+7;
int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n+1);
	for(ll i=1;i<=n;i++)	
		cin>>v[i];
	map<ll,vector<ll>> mp;
	set<ll> s;
	for(ll i=1;i<=n;i++)
		s.insert(i);
	for(ll i=0;i<m;i++)
	{
		ll c,d;
		cin>>c>>d;
		vector<ll> e;
		for(ll i=0;i<2*d;i++)
		{
			ll temp;
			cin>>temp;
			if(i%2==1)
				s.erase(temp);
			e.push_back(temp);
		}
		mp[c]=e;
	}
	while(!s.empty())
	{
			
		ll c = *s.begin();
		// cout<<c<<endl;
		s.erase(c);
		if(mp.find(c)==mp.end() or v[c]==0)
			continue;
		vector<ll> e = mp[c];
		for(ll i=1;i<e.size();i=i+2)
		{
			v[e[i]]=(v[e[i]]+(v[c]*e[i-1])%mod)%mod;
			s.insert(e[i]);
		}
		v[c]=0;
	}
	for(ll i=1;i<=n;i++)
		cout<<v[i]<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
