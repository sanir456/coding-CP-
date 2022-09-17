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
		ll n,a,b;
		cin>>n>>a>>b;
		if(a>(n/2+1) || b<n/2 || (a==n/2+1 && b>a) || (b==n/2 && a<b))
		{
			cout<<-1<<endl;
			continue;
		}
		vector<ll> v(n+1,0);
		cout<<a;
		v[a]=1;
		v[b]=1;
		ll temp = n/2-1;
		ll i = n;
		while(temp)
		{
			if(v[i]==0)
			{
				cout<<" "<<i;
				temp--;
			}
			i--;
		}
		cout<<" "<<b;
		temp = n/2-1;
		while(temp)
		{
			if(v[i]==0)
			{
				cout<<" "<<i;
				temp--;
			}
			i--;
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
