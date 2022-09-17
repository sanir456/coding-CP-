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


bool isValid(vector<ll> psum,ll mid,ll n)
{
	if(psum[mid]>=n)
		return false;
	return true;
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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(k);
		for(ll i=0;i<k;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		vector<ll> psum(k);
		psum[0]=n-v[0];
		for(ll i=1;i<k;i++)
			psum[i]=n-v[i]+psum[i-1];
		// for(ll i:psum)
		// 	cout<<i<<" ";
		// cout<<endl;
		ll l=0;
		ll r=k-1;
		ll ans = 0;
		while(l<=r)
		{
			ll mid = l + (r-l)/2;
			if(isValid(psum,mid,n))
			{
				ans = max(ans,mid);
				l = mid+1;
			}
			else
				r = mid-1;
		}
		cout<<ans+1<<endl;

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
