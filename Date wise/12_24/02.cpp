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
		ll l,r;
		cin>>l>>r;
		vector<vector<ll>> dp(200001,vector<ll>(20,0));
		for(ll i=0;i<200001;i++)
		{
			ll c = i;
			ll idx = 0;
			while(c)
			{
				dp[i][idx]+=(c%2);
				idx++;
				c>>=1;
			}
			if(i==0) continue;

			for(ll j=0;j<20;j++)
			{
				dp[i][j]+=dp[i-1][j];
			}
		}

		ll ans = 0;
		for(ll i=0;i<20;i++)
			ans = max(ans,dp[r][i]-dp[l-1][i]);
		cout<<(r-l+1-ans)<<endl;
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
