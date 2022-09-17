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
	
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll> pre(n+1);
	pre[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>pre[i];
		pre[i]+=pre[i-1];
		// cout<<pre[i]<<" ";
	}
	// cout<<endl;
	multiset<ll> s;
	for(ll i=a;i<=b;i++)
		s.insert(pre[i]);
	ll ans = -INFF;
	for(ll i=1;i+a-1<=n;i++)
	{
		// for(auto k:s)
		// 	cout<<k<<" ";
		
		// cout<<i<<endl;
		ans = max(ans,*s.rbegin()-pre[i-1]);
		s.erase(pre[i+a-1]);
		if(i+b<=n)
			s.insert(pre[i+b]);
		
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
