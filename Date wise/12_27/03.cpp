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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n);
		ll sum = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			sum+=v[i];
		}
		if(n==1)
		{
			if(k>=v[0]) cout<<0<<endl;
			else cout<<sum-k<<endl;
			continue;
		}

		sort(v.begin(),v.end());	
		vector<ll> p(n);
		p[0]=0;
		p[1] = v[1];
		for(ll i=2;i<n;i++)
			p[i]=p[i-1]+v[i];
		if(sum<=k)
				cout<<0<<endl;
		else
		{
			ll mi = v[0];
			ll ans = INT_MAX;
			for(ll i=n-1;i>=0;i--)
			{
				ll temp = p[i]-k;
				if(temp==0 && i==n-1)
				{
					ans = min(ans,mi);
				}
				else
				{
					ll value = ceil((double)temp/(n-i));
					ans = min(ans,n-1-i+(mi-value));
				}
				cout<<i<<" "<<temp<<" "<<value<<" "<<ans<<endl;
			}
			cout<<ans<<endl;
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
