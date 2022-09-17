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

bool comp(pair<ll,pair<ll,ll>> i,pair<ll,pair<ll,ll>> j)
{
	if(i.second.second>j.second.second) return false;
	return true;
}

bool comp1(pair<ll,pair<ll,ll>> i,pair<ll,pair<ll,ll>> j)
{
	if(i.second.first>j.second.first) return false;
	return true;
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
		
		
		string s;
		getline(cin,s);
		ll n,m;
		cin>>n>>m;
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<m;i++)
		{
			ll x,w;
			cin>>x>>w;
			v.push_back(make_pair(i+1,make_pair(x,w)));	
		}
		sort(v.begin(),v.end(),comp);
		sort(v.begin(),v.begin()+2*n,comp1);
		ll l=0;
		ll r=2*n-1;
		ll ans=0;
		for(ll i=0;i<2*n;i++)
			ans=ans + v[i].second.second;
		cout<<ans<<endl;
		for(ll i=0;i<n;i++)
			cout<<v[i].first<<" "<<v[2*n-1-i].first<<endl;
		cout<<endl;
			
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
