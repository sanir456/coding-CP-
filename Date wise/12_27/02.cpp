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
		vector<int> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		string s;
		cin>>s;
		priority_queue<pair<ll,ll>> l;
		priority_queue<pair<ll,ll>> d;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
				d.push({v[i],i});
			else
				l.push({v[i],i});
		}
		vector<ll> ans(n);
		int r = n;
		while(!l.empty())
		{
			ans[l.top().second]=r;
			r--;
			l.pop();
		}

		while(!d.empty())
		{
			ans[d.top().second]=r;
			r--;
			d.pop();
		}
		for(ll i=0;i<n;i++)
			cout<<ans[i]<<" ";
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
