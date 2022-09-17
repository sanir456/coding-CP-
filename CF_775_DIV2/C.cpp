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

ll sumPairs(vector<ll> v)
{
    ll sum = 0;
    ll n = v.size();
    sort(v.begin(),v.end());
    // for(ll i=0;i<n;i++)
    // 	cout<<v[i]<<" ";
    // cout<<endl;
    // if(n<2)
    // 	return 0;
    for (ll i=n-1; i>=0; i--)
        sum += i*v[i] - (n-1-i)*v[i];
    return sum;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,m;
	cin>>n>>m;
	map<ll,vector<ll>> vr;
	map<ll,vector<ll>> vc;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			ll temp;
			cin>>temp;
			vr[temp].push_back(i);
			vc[temp].push_back(j);
		}
	}
	ll ans = 0;
	for(auto i:vr)
	{
		ans+=sumPairs(i.second);
		// cout<<ans<<' ';
	}
	// cout<<endl;
	
	for(auto i:vc)
	{
		ans+=sumPairs(i.second);
		// cout<<ans<<" ";
	}
	// cout<<endl;
	cout<<ans<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
