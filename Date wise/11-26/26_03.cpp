#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TC(t) while(t--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define FOR(a,b,c) for(ll(a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll(a)=(b);(a)<=(c);++(a))
#define FORED(a,b,c) for(ll(a)=(b);(a)>=(c);--(a))
#define FOREACH(a,b) for(auto&(a):(b))

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("G:/Personal/CP/input.txt", "r", stdin);
	freopen("G:/Personal/CP/output.txt", "w", stdout);
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
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			v.push_back({temp,i});
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ll sum = 0;
		vector<ll> d(n);
		ll l = -1;
		ll r = 1;
		for(ll i=0;i<n;i++)
		{
			if(i%2==0)
			{
				d[v[i].second]=r;
				sum += (r*2*v[i].first);
				r++;
			}
			else
			{
				d[v[i].second]=l;
				sum += (abs(l)*2*v[i].first);
				l--;
			}
		}
		cout<<sum<<endl;
		cout<<"0 ";
		for(ll i=0;i<n;i++)
			cout<<d[i]<<" ";

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
