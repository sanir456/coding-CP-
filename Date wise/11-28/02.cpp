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
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];

		ll ans1 = 0;
		sort(v.begin(),v.end());
		vector<ll> v2 = v;
		if(n==1)
		{
			cout<<v[0]<<endl;
			continue;
		}
		ll temp = -1;
		if(v[n-1]%2==0)
		{
			int idx = lower_bound(v.begin(),v.end(),v[n-1]/2)-v.begin();
			for(int i = idx;i<n-1;i++)
			{
				if(v[i]%2!=0)
					temp = i;	
			}
		}
		int idx;
		if(temp==-1)
			idx = n-1;
		else
			idx = temp;
		temp = v[idx];
		for(ll i=0;i<n;i++)
		{
			if(i==idx)
				continue;
			while(v[i]%2==0)
			{
				temp=temp<<1;
				v[i]/=2;
			}		
			ans1 += v[i];
		}
		// cout<<ans<<endl;
		ans1+=temp;


		ll ans2 = 0;
		temp = -1;
		if(v2[n-1]%4==0)
		{
			int idx = lower_bound(v2.begin(),v2.end(),v2[n-1]/4)-v2.begin();
			// cout<<idx<<endl;
			for(int i = idx;i<n-1;i++)
			{
				if(v2[i]%2!=0)
					temp = i;	
			}
		}
		if(temp==-1)
			idx = n-1;
		else
			idx = temp;
		temp = v2[idx];
		// cout<<temp<<endl;
		for(ll i=0;i<n;i++)
		{
			if(i==idx)
				continue;
			while(v2[i]%2==0)
			{
				// cout<<v2[i]<<endl;
				temp=temp<<1;
				v2[i]/=2;
			}		
			ans2 += v2[i];
		// cout<<ans2<<" "<<temp<<endl;
		}
		// cout<<ans<<endl;
		ans2+=temp;

		cout<<max(ans1,ans2)<<endl;
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
