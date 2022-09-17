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
		for(ll i=0;i<m;i++)
		{
			ll stone = 0;
			for(ll j=0;j<n;j++)
			{
				if(v[j][i]=='*')
				{
					v[j][i]='.';
					stone++;
				}
				
				if(v[j][i]=='o' or j==n-1)
				{
					// cout<<stone<<" ";
					if(v[j][i]=='o')
					{
						// cout<<"v[j][i]=='o' "<<j<<endl;
						for(ll k=1;k<=stone;k++)
							v[j-k][i]='*';
					}
					else
					{
						
						// cout<<"j==n-1 "<<j<<endl;
						for(ll k=0;k<stone;k++)
							v[j-k][i]='*';	
					}
					stone=0;
				
				}
				// cout<<endl;
			}
		}
		for(ll i=0;i<n;i++)
			cout<<v[i]<<endl;
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
