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
	

	ll n,m;
	cin>>n>>m;
	ll mod=1e9+7;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
			cin>>v[i];
	vector<vector<ll>> dp(n,vector<ll>(m+1,0));
	if(v[0]==0)
	{
		for(ll i=1;i<=m;i++)
			dp[0][i]=1;
	}
	else
		dp[0][v[0]]=1;
	
	for(ll i=1;i<n;i++)
	{
		if(v[i]==0)
		{
			for(ll k=1;k<=m;k++)
			{
				for(ll l=-1;l<2;l++)
				{
					if(k+l>0 and k+l<=m)
						dp[i][k]=(dp[i][k]+dp[i-1][k+l])%mod;
				}
			}
		}
		else
		{
			for(ll l=-1;l<2;l++)
			{
				if(v[i]+l>0 and v[i]+l<=m)
					dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]+l])%mod;
			}	
		}
	}
	ll ans=0;
	for(ll i=1;i<=m;i++)
		ans=(ans+dp[n-1][i])%mod;
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
