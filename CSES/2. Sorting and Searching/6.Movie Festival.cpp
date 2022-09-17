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

bool comp(pair<ll,ll> i,pair<ll,ll> j)
{
	return (i.second<j.second);
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n;
	cin>>n;
	vector<pair<ll,ll>> v;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	sort(all(v),comp);
	ll c=1,e=v[0].second;
	// cout<<e<<endl;
	for(ll i=1;i<n;i++)
	{
		if(v[i].first>=e)
		{
			c++;
			e=v[i].second;
		}
	}
	cout<<c<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
