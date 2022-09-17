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
		string s;
		ll k,n;
		cin>>n>>k;
		cin>>s;

		vector<int> dp(n,0);
		vector<int> maxL(26,0);
		for(ll i=0;i<n;i++)
		{
			ll c = s[i]-'a';
			ll l = max(0LL,c-k);
			ll r = min(25LL,c+k);
			for(ll j=l;j<=r;j++)
				dp[i]=max(dp[i],maxL[j]+1);
			maxL[c]=max(dp[i],maxL[c]);
		}
		ll ans = 0;
		for(ll i:dp)
			ans=max(ans,i);
		cout<<ans<<endl;
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
