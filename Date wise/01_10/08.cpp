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
		ll n;
		cin>>n;
		vector<ll> v(n+1);
		v[0]=1;
		bool ok = true;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			while(temp>0)
			{
				if(temp<=n and v[temp]==0)
				{
					v[temp]=1;
					break;
				}
				
				temp=temp/2;

			}
		}
		for(ll i=0;i<=n;i++)
		{
			if(v[i]==0)
			{
				ok = false;
				break;
			}
		}
		cout<<(ok?"YES":"NO")<<endl;
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
