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
		vector<string> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		if(v[0][0]=='1')
		{
			cout<<-1<<endl;
			continue;
		}
		ll ans = 0;
		vector<vector<ll>> r;
		for(ll i=n-1;i>=0;i--)
		{
			for(ll j=m-1;j>=0;j--)
			{
				if(v[i][j]=='1')
				{
					ans++;
					if(j==0)
						r.push_back({i,1,i+1,1});
					else
						r.push_back({i+1,j,i+1,j+1});
				}
			}
		}
		cout<<ans<<endl;
		for(auto i : r)
		{
			for(auto j : i)
				cout<<j<<" ";
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
