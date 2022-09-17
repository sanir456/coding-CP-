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
	for(ll k=1;k<=t;k++)
	{
		ll n,d;
		cin>>n>>d;
		vector<ll> v(n);
		for(ll j=0;j<n;j++)
			cin>>v[j];
		ll up = 0;
		ll down = 0;
		ll ans = 0;
		// google(k);
	
		if(d==2)
		{
			for(ll i=0;i<n;)
			{
				if(v[i]==1)
				{
					up++;
					while(i<n and v[i]==1)
						i++;
				}
				else
				{
					down++;
					while(i<n and v[i]==0)
						i++;
				}
			}
			
			cout<<up<<endl;
		}
		else
		{
			vector<ll> s(d);	
			ll mx = INT_MIN;
			ll d1;
			for(ll i=0;i<n;)
			{
				ll D = v[i];
				if(v[i]==D)
				{
					s[D]++;
					while(i<n and v[i]==D)
						i++;
				}
				if(s[D]>mx)
				{
					mx = s[D];
					d1 = D;
				}
				else if(s[D]==mx)
				{
					if(d1>d-D)
						d1=D;
				}
			}
			ll l=0;
			ll r=d-1;
			while(l<r)
			{
				swap(s[l],s[r]);
				l++;
				r--;
			}
			l=0;
			r=d1-1;
			while(l<r)
			{
				swap(s[l],s[r]);
				l++;
				r--;
			}
			l=d1;
			r=d-1;
			while(l<r)
			{
				swap(s[l],s[r]);
				l++;
				r--;
			}
			for(auto i:s)
				cout<<i<<endl;
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
