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
		ll n,m,r,c;
		cin>>n>>m>>r>>c;
		r--;
		c--;
		vector<string> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		bool ok = false;
		if(v[r][c]=='B')
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(v[i][c]=='B')
			{
				ok = true;
				cout<<1<<endl;
				break;
			}
		}
		if(ok)
			continue;

		for(int i=0;i<m;i++)
		{
			if(v[r][i]=='B')
			{
				ok = true;
				cout<<1<<endl;
				break;
			}
		}
		if(!ok)
		{
			for(int i=0;i<n and !ok;i++)
			{
				for(int j=0;j<m and !ok;j++)
				{
					if(v[i][j]=='B')
					{
						ok=true;
						cout<<2<<endl;
					}
				}
			}
		}
		if(!ok)
			cout<<-1<<endl;
			

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

