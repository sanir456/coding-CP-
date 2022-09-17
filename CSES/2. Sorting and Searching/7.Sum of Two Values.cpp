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
	vector<pair<ll,ll>> v;
	for(ll i=1;i<=n;i++)
	{
		ll temp;
		cin>>temp;
		v.push_back({temp,i});
	}
	sort(all(v));
	bool ok = true;
	for(ll i=0;i<n;i++)
	{
		if(v[i].first>(x+1)/2)
		{
			cout<<"IMPOSSIBLE";
			ok= false;
			break;
		}
		pair<ll,ll> p = {x-v[i].first,0};
		ll idx = lower_bound(v.begin(),v.end(),p) - v.begin();
		if(v[idx].first+v[i].first == x and i!=idx)
		{
			cout<<v[i].second<<" "<<v[idx].second<<endl;
			ok=false;
			break;
		}
	}
	if(ok)
			cout<<"IMPOSSIBLE";
		
	
	


	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}