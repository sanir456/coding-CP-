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
		ll x,y;
		cin>>x>>y;
		ll ans = 0;
		for(int i=0;i<4;i++)
		{
			ll x1;
			cin>>x1;
			ll mn=INT_MAX,mx=INT_MIN;
			for(ll i=0;i<x1;i++)
			{
				ll temp;
				cin>>temp;
				mn=min(mn,temp);
				mx=max(mx,temp);
			}
			if(i<2)
				ans = max(ans,(mx-mn)*y);
			else

				ans = max(ans,(mx-mn)*x);
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
