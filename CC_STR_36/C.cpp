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

bool comp(pair<ll,ll>& i,pair<ll,ll>& j)
{
	if(i.first<j.first)
		return true;
	else if(i.first==j.second)
	{
		if(i.second<j.second)
			return true;
	}
	return false;
}


//unsolve

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,r;
		cin>>n>>r;
		vector<pair<ll,ll>> v(n,{0,0});
		for(ll i=0;i<n;i++)
			cin>>v[i].second;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			v[i].first=v[i].second-temp;
		}
		sort(all(v),comp);
		ll ans = 0;
		for(auto i:v)
		{
			if(r>0 and r>=i.second)
			{
				ll temp = (r-i.second)/i.first+1;
				ans+=temp;
				r-=(temp)*(i.first);
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
