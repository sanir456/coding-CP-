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
	
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	pair<ll,ll> dp[1<<n];
	dp[0]={0,k+1};
	for(ll i=1;i<(1<<n);i++)
	{
		dp[i]={25,0};
		for(ll j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				pair<ll,ll> p=dp[i^(1<<j)];
				if(p.second+v[j]>k)
				{
					
					p.first++;
					p.second=min(p.second,v[j]);
				}
				else
					p.second+=v[j];
				dp[i]=min(dp[i],{p.first,p.second});
			}
							
		}
	}
	// for(auto i:dp)
	// 	cout<<i.first<<" "<<i.second<<endl;
	cout<<dp[(1<<n)-1].first<<endl;
	  

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
	
}
