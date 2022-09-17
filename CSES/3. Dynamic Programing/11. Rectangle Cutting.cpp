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
	if(n>m) swap(n,m);
	vector<vector<ll>> dp(505,vector<ll>(505));
	for(ll i=0;i<=m;i++) dp[i][i]=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=m;j++)
		{
			dp[i][j]=INFF;
			for(ll k=1;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
			}
			
			for(ll k=1;k<i;k++)
			{
				dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
			}
			dp[j][i]=dp[i][j];
		}
	}	
	cout<<dp[n][m]<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
