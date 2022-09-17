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
		ll n,a,b;
		cin>>n>>a>>b;
		ll ans=0;
		bool ok=false;
		for(ll i=n-1;i>=0;i--)
		{
			ll bita=(a>>i)&1;
			ll bitb=(b>>i)&1;
			if(bita==0 and bitb==0)
				ans+=pow(2,i);
			else if(bita!=bitb)
			{
				if(ok)
				{
					if(bita==0)
						ans+=pow(2,i);	
				}
				else
				{
					if(bita==0)
						ok=!ok;
					else
					{
						ok=!ok;
						ans+=pow(2,i);	
					}
				}
			}
				
				
				
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
