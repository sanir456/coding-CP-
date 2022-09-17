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
	
	ll n;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if(sum%2==1)
	{
		cout<<0<<endl;
		return 0;
	}
	ll mod=1e9+7;
	sum/=2;
	vector<vector<ll>> dp(n,vector<ll>(sum+1,0));
	for(ll i=0;i<n;i++)\
	{
		for(ll j=0;j<=sum;j++)
		{
			if(i==0 and j==0) dp[i][j]=1;
			if(i==0) continue;
			if(j==0) dp[i][j]=1;
			else
			{
				if(i<=j)
					dp[i][j]=(dp[i-1][j]+dp[i-1][j-i])%mod;
				else
					dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n-1][sum]<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
