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
		ll n,l;
		cin>>n>>l;
		vector<ll> ones(l,0);
		vector<ll> zeros(l,0);
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			for(ll j = 0;j<l;j++)
			{
				if(temp>>j & 1)
					ones[j]++;
				else
					zeros[j]++;
			}
		}-
		ll ans = 0;
		// for(ll i=l-1;i>=0;i--)
		// 	cout<<ones[i]<<" ";
		// cout<<endl;
		// for(ll i=l-1;i>=0;i--)
		// 	cout<<zeros[i]<<" ";
		// cout<<endl;
		for(ll i=l-1;i>=0;i--)
		{
			// cout<<ans<<endl;
			ll temp=(ones[i]>zeros[i])?1:0;
			ans = ans*2 + temp;
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
