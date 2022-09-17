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

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		vector<ll> sum(n+1,INT_MIN);
		sum[0]=0;
		for(ll i=1;i<n+1;i++)
		{
			ll s = 0;
			for(ll j=0;j<i;j++)
				s+=v[j];
			sum[i]=max(sum[i],s);
			for(ll j=i;j<n;j++)
			{
				s = s+v[j]-v[j-i];
				sum[i]=max(sum[i],s);
			}	
		}
		// for(auto s:sum)
		// 	cout<<s<<" ";
		// cout<<endl;
		for(ll i=0;i<n+1;i++)
		{
			ll ans = INT_MIN;
			for(ll j=0;j<n+1;j++)
			{
				// cout<<sum[j]+x*j<<" ";
				ans = max(ans,sum[j]+x*min(i,j));
			}
			cout<<ans<<" ";
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
