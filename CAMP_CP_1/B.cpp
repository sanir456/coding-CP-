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
	
	ll n;
	cin>>n;
	vector<vector<ll>> v(n,vector<ll>(n));
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>v[i][j];
	
	ll ans  = -1;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			for(ll k = 1 ; k<min(n-i,n-j);k++)
			{
					// cout<<i<<" "<<j<<" "<<k<<endl;
				if(v[i][j]==v[i+k][j] and v[i][j]==v[i][j+k] and v[i][j]<v[i+k][j+k])
				{
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<1<<endl;
					ans = max(ans,v[i][j]);
				}
				else if(v[i][j]<v[i+k][j] and v[i][j]==v[i][j+k] and v[i][j]==v[i+k][j+k])
				{
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<2<<endl;
					ans = max(ans,v[i][j]);
				}
				else if(v[i][j]==v[i+k][j] and v[i][j]<v[i][j+k] and v[i][j]==v[i+k][j+k])
				{
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<3<<endl;
					ans = max(ans,v[i][j]);
				}
				else if(v[i][j]>v[i+k][j] and v[i+k][j]==v[i][j+k] and v[i+k][j]==v[i+k][j+k])
				{
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<4<<endl;
					ans = max(ans,v[i+k][j]);
				}
			}
			// cout<<ans<<" ";
		}

	}
	cout<<ans<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
