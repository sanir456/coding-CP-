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
		ll n;
		cin>>n;
		vector<ll> v(2*n);
		ll o=0;
		ll e=0;
		vector<ll> even;
		for(ll i=0;i<2*n;i++)
		{
			cin>>v[i];
			if(v[i]%2==0)
			{
				e++;
				ll temp=v[i];
				ll i=0;
				while(temp%2==0)
				{
					i++;
					temp/=2;
				}
				even.push_back(i);
			}
			else
				o++;
			
		}
		if(o==e)
		{
			cout<<0<<endl;
			continue;
		}
		else if(o>e)
		{
			// cout<<o<<e<<endl;
			cout<<(o-e)/2<<endl;
			continue;
		}
		else
		{
			sort(all(even));
			ll ans=0;
			for(ll i=0;i<(e-o)/2;i++)
				ans+=even[i];
			cout<<ans<<endl;	
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
