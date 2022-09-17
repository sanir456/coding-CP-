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

bool comp(pair<pair<ll,ll>,ll>& i,pair<pair<ll,ll>,ll>& j)
{
	if(i.first.first==j.first.first)
	{
		if(i.first.second>j.first.second)
			return true;
		else
			return false;
	}
	return i.first.first<j.first.first;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n;
	cin>>n;
	vector<pair<pair<ll,ll>,ll>> v(n);
	vector<ll> ans1(n);
	vector<ll> ans2(n);
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v[i]={{x,y},i};
	}
	
	
	sort(all(v),comp);
	
	// for(auto i:v)
	// 	cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
	
	ll mn = INT_MAX;
	
	
	
	for(ll i=n-1;i>=0;i--)
	{
		if(v[i].first.second>=mn)
			ans1[v[i].second]=1;
		mn = min(mn,v[i].first.second);
	}
	ll mx = 0;
	for(ll i=0;i<n;i++)
	{
		if(v[i].first.second<=mx)
			ans2[v[i].second]=1;
		mx = max(mx,v[i].first.second);
	}
	
	for(auto i:ans1)
		cout<<i<<" ";
	cout<<endl;
	for(auto i:ans2)
		cout<<i<<" ";
	cout<<endl;

	
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
