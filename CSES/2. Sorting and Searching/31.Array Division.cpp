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

ll isValid(ll mid,vector<ll> v,ll k,ll ss)
{
	ll g = 0;
	ll s = ss;
	for(ll i=0;i<v.size();)
	{
		ll sum = 0;
		
		while(i<v.size() and sum+v[i]<=mid)
		{
			
			sum+=v[i];
			i++;
			if(i<v.size() and v[i]>mid)
				return ss;
		}
		g++;
		s = min(sum,s);
		if(g>k)
			return ss;
	}	
	return s;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,k;
	cin>>n>>k;
	ll sum = 0;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	ll l = 0;
	ll r = sum;
	ll ans = r;
	
	while(l<=r)
	{
		// cout<<l<<" "<<r<<endl;
		ll mid = l + (r-l)/2;
		if(isValid(mid,v,k,sum)!=sum)
		{
			ans = mid;
			r = mid-1;
		}
		else
			l = mid+1;
	}
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
