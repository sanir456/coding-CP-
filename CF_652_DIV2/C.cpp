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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		ll ans = 0;
		for(ll i=n-1;i>=n-k;i--)
			ans += v[i];
		vector<ll> v1(k);
		for(ll i=0;i<k;i++)
		{
			cin>>v1[i];
			v1[i]--;
		}
		sort(v1.begin(),v1.end());
		reverse(v1.begin(),v1.end());
		ll i=0;
		for(ll j=0;i<k;i++)
		{
			if(v1[i]==0)
				break;
			else
			{
				ans += v[j];
				j+=v1[i];
			}
		}
		i = k-i;
		ll j=n-1;
		// cout<<ans<<endl;
		while(i--)
		{
			ans+=v[j];
			j--;			
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
