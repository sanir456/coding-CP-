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
	
		string s1,s2;
		cin>>s1>>s2;
		
		ll n=s1.size();
		ll m=s2.size();
		vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
		for(ll i=0;i<=n;i++)
		{
			for(ll j=0;j<=m;j++)
			{
				if(i==0) dp[i][j]=j;
				else if(j==0) dp[i][j]=i;
				else
				{
					ll c = (s1[i-1]!=s2[j-1]);
            		dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + c});
				}
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
