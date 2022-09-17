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
		ll n,q;
		cin>>n>>q;
		vector<vector<ll>> dp(1001,vector<ll>(1001,0));
		for(int i=0;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			dp[x][y]+=x*y;
		}
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				
			}
		}
		// for(int i=0;i<4;i++)
		// {
		// 	for(int j=0;j<4;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<endl;
		// }
		while(q--)
		{
			ll h1,w1,h2,w2;
			cin>>h1>>w1>>h2>>w2;
			ll ans=dp[h2-1][w2-1]-dp[h1][w2-1]-dp[h2-1][w1]+dp[h1][w1];
			// cout<<dp[h2-1][w2-1]<<" "<<dp[h1][w2-1]<<" "<<dp[h2-1][w1]<<" "<<dp[h1][w1]<<endl;
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
