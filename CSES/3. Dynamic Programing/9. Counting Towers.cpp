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
	ll mod =1e9+7;
	vector<vector<ll>> dp(1000001,vector<ll>(2,0));
	dp[0][0]=1;
	dp[0][1]=1;
	for(ll i=1;i<1000001;i++)
	{
		dp[i][0]=((dp[i-1][0]*4)%mod+dp[i-1][1])%mod;
		dp[i][1]=((dp[i-1][1]*2)%mod+dp[i-1][0])%mod;
	}
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
		
		
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
