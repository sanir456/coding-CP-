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

bool isValid(ll mid,vector<ll> v,ll p)
{
	for(ll i=0;i<v.size();i++)
	{
		// cout<<p<<" ";
		if(p<=0)
			return true;
		p-=mid/v[i];
	}
	// cout<<p<<endl;
	return p<=0;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
		
	ll m,p;
	cin>>m>>p;
	vector<ll> v(m);
	for(ll i=0;i<m;i++)
		cin>>v[i];
	
	sort(all(v));
	ll l = 1;
	ll r = INFF;
	ll ans = r;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		// cout<<mid<<" ";
		if(isValid(mid,v,p))
		{
			ans = mid;
			r = mid-1;
		}
		else
			l = mid + 1;
			
	}
	cout<<ans;
	

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
