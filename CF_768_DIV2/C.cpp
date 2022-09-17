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
	// cout<<(0^0)<<endl;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll m = log2(n);
		vector<pair<ll,ll>> ans(n/2);
		bool ok =true;
		vector<bool> vi(n,false);
		ll p=0;
		cout<<k<<endl;
		for(ll i = 0;i<n;i++)
		{
			if(vi[i])
				continue;
			else
				vi[i]=true;
			vector<ll> v(m);
			for(ll j=0;j<m;j++)
			{
				v[j] = (i>>j & 1)&(k>>j & 1);
			}
			ll t = 0;
			for(ll j = m-1;j>=0;j--)
			{
				// cout<<v[j]<<" ";
				t= t*2 + v[j];
			}
			// cout<<t<<endl;
			if(vi[t])
			{
				ok = false;
				break;
			}
			else
			{
				vi[t]=true;
				ans[p]={i,t};
				p++;
			}
		}
		if(ok)
		{
			for(auto i:ans)
			{
				cout<<i.first<<" "<<i.second<<endl;
			}
		}
		else
			cout<<-1<<endl;
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
