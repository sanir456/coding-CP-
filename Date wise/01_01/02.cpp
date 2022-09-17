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

bool isValid(vector<ll> v,ll k,ll h)
{
	ll p = 0;
	ll n = v.size();
	for(int i=0;i<n-1;i++)
	{
		p+=min(k,v[i+1]-v[i]);
		if(p>=h)
			return true;
	}
	p+=k;
	return p>=h;
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
		ll n,h;
		cin>>n>>h;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];

		ll l = 0;
		ll r = h;
		ll ans = INFF;
		while(l<=r)
		{
			ll mid = l + (r-l)/2;
			if(isValid(v,mid,h))
			{
				ans = min(ans,mid);
				r = mid-1;				
			}
			else
				l = mid+1;
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
