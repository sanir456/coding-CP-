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

ll fun(vector<ll>& v,ll p)
{
	ll idx = -1;
	ll n = v.size();
	for(ll i=0;i<=p;i++)
	{
		if(v[i]==p+1)
		{
			idx = i;
			break;
		}
	}
	if(idx == p)
		return 0;
	else
	{
		ll l=0;
		ll r=p;
		while(l<r)
		{
			swap(v[l],v[r]);
			l++;
			r--;
		} 
		l=0;
		r=p-idx-1;
		while(l<r)
		{
			swap(v[l],v[r]);
			l++;
			r--;
		} 
		
		l=p-idx;
		r=p;
		while(l<r)
		{
			swap(v[l],v[r]);
			l++;
			r--;
		} 
		return idx+1;
	}
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
		vector<ll> v(n);
		for(ll i=0;i<n;i++)cin>>v[i];
		vector<ll> ans(n);
		for(ll i=n-1;i>=0;i--)
			ans[i]=fun(v,i);
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
