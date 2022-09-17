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
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	ll sum=0;
	ll ans = 0;
	ll l = 0;
	ll r = 0;
	while(r<n)
	{
		if(sum==x)
		{
			ans++;
			sum-=v[l++];
			sum+=v[r++];
		}
		else if(sum<x)
			sum+=v[r++];
		else
			sum-=v[l++];
			
	}
	while(sum>=x and l<n)
	{
		if(sum==x)
			ans++;
		sum-=v[l++];
	}
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
