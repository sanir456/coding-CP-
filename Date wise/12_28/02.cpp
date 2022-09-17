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


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

bool comp(const pair<ll,ll> &p1,const pair<ll,ll> &p2)
{
	if(p1.first<p2.first) return true;
	else if(p1.first==p2.first)
	{
		if(p1.second>p2.second)
			return true;
		else
			return false;
	}
	else
		return false;
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
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v(n);
		map<pair<ll,ll>,ll> m;
		for(int i=0;i<n;i++)
		{
			cin>>v[i].first>>v[i].second;
		}
		sort(v.begin(),v.end(),comp);
		vector<ll> ans(n);
		for(int i=0;i<n-1;i++)
		{
			if(v[i].first==v[i].second)
				cout<<v[i].first<<" "<<v[i].second<<" "<<v[i].second<<endl;
			else if(v[i].first==v[i+1].first)
				cout<<v[i].first<<" "<<v[i].second<<" "<<v[i+1].second+1<<endl;
			else if(v[i].second==v[i+1].second)
				cout<<v[i].first<<" "<<v[i].second<<" "<<v[i+1].first-1<<endl;
		}
		cout<<v[n-1].first<<" "<<v[n-1].second<<" "<<v[n-1].first<<endl;
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
