#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define FOR(i,a,b) for(ll i = a;i<b;i++)

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

	vector<bool> prime(1000005,false);
	vector<bool> use(1000005,false);
	
	FOR(i,2,1000005) 
	{
		if (!use[i])
		{
	        prime[i] = true;
	        for (int j = i; j < 1000005; j += i) 
	            use[j] = true;
	        
	    	}
	}

	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n);
		FOR(i,0,n)
			cin>>v[i];

		ll ans = 0;
		FOR(i,0,n)
		{
			if(prime[v[i]])
			{
				ll r=1,l=1;
				while(r*k+i<n and v[r*k+i]==1) r++;
				while(i-l*k>=0 and v[i-l*k]==1) l++;
				ans+=l*r-1;
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
