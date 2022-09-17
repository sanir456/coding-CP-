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
	
	ll n,x;
	cin>>n>>x;
	x++;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	map<ll,ll> m;
	ll ans = 0;
	ll k = 0;
	ll l=0;
	ll r=0;
	while(r<n)
	{
		if(m[v[r]]==0)
			k++;
		m[v[r]]++;
		if(k==x)
			ans+=(n-r);
		
		while(l<r and k==x)
		{
			if(m[v[l]]>1)
				ans+=(n-r);
			else
				k--;
			m[v[l]]--;
			l++;
		}
		r++;	
	}
	cout<<((n)*(n+1))/2-ans<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
