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


vector<ll> v(5005);
vector<vector<ll>> dp(5005,vector<ll>(5005,-1));
	
	

ll fun(ll i,ll j)
{
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans1=v[i]+min(fun(i+1,j-1),fun(i+2,j));
	ll ans2=v[j]+min(fun(i+1,j-1),fun(i,j-2));
	return dp[i][j]=max(ans1,ans2);
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>v[i];
	cout<<fun(0,n-1)<<endl;	
	
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
