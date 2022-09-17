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
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll x1,y1;
		cin>>x1>>y1;
		ll x2,y2;
		cin>>x2>>y2;
		vector<vector<ll>> ans(n+1,vector<ll>(m+1,0));
		ans[x1][y1]=1;
		ans[x2][y2]=2;
		if((abs(x1-x2)+abs(y1-y2))%2==0)
		{
			if(x1-1>=1)
				ans[x1-1][y1]=3;
			if(y1-1>=1)
				ans[x1][y1-1]=3;
			if(x1+1<=n)
				ans[x1+1][y1]=3;
			if(y1+1<=m)
				ans[x1][y1+1]=3;
		}
		for(ll i = y2;i>=1;i=i-2)
		{
			for(ll j=x2;j>=1;j=j-2)
			{
				if(ans[j][i]==0)
					ans[j][i]=2;
			}	
			
			for(ll j=x2+2;j<=n;j=j+2)
			{
				if(ans[j][i]==0)
					ans[j][i]=2;
			}	
		}
		
		for(ll i = y2+2;i<=m;i=i+2)
		{
			for(ll j=x2;j>=1;j=j-2)
			{
				if(ans[j][i]==0)
				ans[j][i]=2;
			}	
			
			for(ll j=x2+2;j<=n;j=j+2)
			{
				if(ans[j][i]==0)
				ans[j][i]=2;
			}	
		}
		x2--;
		y2--;
		
		for(ll i = y2;i>=1;i=i-2)
		{
			for(ll j=x2;j>=1;j=j-2)
			{
				if(ans[j][i]==0)
					ans[j][i]=2;
			}	
			
			for(ll j=x2+2;j<=n;j=j+2)
			{
				if(ans[j][i]==0)
					ans[j][i]=2;
			}	
		}
		
		for(ll i = y2+2;i<=m;i=i+2)
		{
			for(ll j=x2;j>=1;j=j-2)
			{
				if(ans[j][i]==0)
				ans[j][i]=2;
			}	
			
			for(ll j=x2+2;j<=n;j=j+2)
			{
				if(ans[j][i]==0)
				ans[j][i]=2;
			}	
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				if(ans[i][j]==0)
					ans[i][j]=1;
			}
		}
		
		
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
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
