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
		ll n,m;
		cin>>n>>m;
		vector<ll> ans;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				ll mx=0;
				mx = max({abs(n-i-1)+abs(m-j-1),abs(i)+abs(m-j-1),abs(n-i-1)+abs(j),abs(i)+abs(j)});
				ans.push_back(mx);
			}
		}
		sort(ans.begin(),ans.end());
		for(ll i=0;i<m*n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
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
