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
	// cout<<t<<endl;
	while(t--)
	{
		ll n;
		cin>>n;
		// cout<<n<<endl;
		vector<vector<ll>> v;
		vector<ll> temp(n);
		map<ll,ll> m1;
		for(ll i=0;i<n;i++)
		{
			// cout<<i<<" ";
			cin>>temp[i];
			m1[temp[i]]++;
		}
		v.push_back(temp);
		for(ll i=1;i<=n;i++)
		{
			map<ll,ll> m2;
			for(ll i=0;i<n;i++)
			{
				temp[i]=m1[temp[i]];
				m2[temp[i]]++;
			}
			v.push_back(temp);
			m1=m2;			
		}
		ll q;
		cin>>q;
		while(q--)
		{
			ll a,k;
			cin>>a>>k;
			// cout<<a<<endl;
			if(k>=n)
				cout<<v[n][a-1]<<endl;
			else
				cout<<v[k][a-1]<<endl;
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

