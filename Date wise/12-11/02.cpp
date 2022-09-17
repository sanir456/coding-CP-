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

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define INF 500000000
#define maxN 11
#define maxK 1001

// int n, k, dp[maxN][maxK];
// vector<int> c[maxN][maxK];


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	ll t;
	cin>>t;
	while(t--)
	{

		ll n, k;
		cin>>n>>k;
		if(!n&&!k) continue;
		ll dp[11][1001];
		vector<ll> c[11][1001];
		for(ll i=1;i<=n;i++)
		{
			ll temp;
			for(ll j=1;j<=n;j++)
			{
				if(i!=j)
				{
					cin>>temp;
					c[i][j].resize(temp);
					for(k=0;k<temp;k++)
					{
						cin>>c[i][j][t];
					}
				}
			}
			for(ll q=1;q<=k;q++)
				dp[i][q]=500000000;
			
		}
		for(ll i=2;i<=n;i++)
			dp[i][1]=c[1][i][0];
		dp[1][1]=0;
		for(ll q=2;q<=k;q++)
		{
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					if(i!=j && dp[j][q-1]!=0)
					{
						ll x = (q-1)%c[j][i].size();
						ll cost = c[j][i][x];
						if(cost==0) continue;
						dp[i][q] = min(dp[i][q],dp[j][q-1]+cost);
					}
				}
			}
		}
		// cout<<dp[n][k]<<endl;
		if(dp[n][k]<500000000) cout<<dp[n][k]<<endl;
		else cout<<-1<<endl;

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
