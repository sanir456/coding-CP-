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
	vector<vector<ll>> v(200006,vector<ll>(30,0));
	for(ll i=1;i<=200005;i++)
	{
		ll temp=i;
		ll j=0;
		while(temp)
		{
			if(temp%2==1)
				v[i][j]=v[i-1][j]+1;
			else	
				v[i][j]=v[i-1][j];
			j++;
			temp/=2;
		}
	}	
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		ll ans=(r-l+1);
		for(ll i=0;i<30;i++)
		{
			// cout<<v[l-1][i]<<" "<<v[r][i]<<endl;
			ans = min(ans,r-l+1 -v[r][i]+v[l-1][i]);
		}
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
