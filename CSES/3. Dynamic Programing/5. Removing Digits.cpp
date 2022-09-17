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

vector<ll> dp(1000001,-1);

ll fun(ll n)
{
	if(dp[n]!=-1)
		return dp[n];
	if(n<10 and n>0)
		return dp[n]=1;
	ll temp=n;
	ll ans=INT_MAX;
	while(temp)
	{
		// cout<<temp<<endl;
		if(temp%10!=0) 
			ans=min(ans,fun(n-temp%10));
		temp/=10;
	}
	return dp[n]=ans+1;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n;
	cin>>n;
	cout<<fun(n)<<endl;
	

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
