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

ll fun(vector<ll> v,ll i)
{
	ll mn = INT_MAX;
	for(ll j=0;j<v.size();j++)
		mn = min(mn,abs(i-v[j]));
	return mn;
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
		vector<ll> a(n);
		vector<ll> b(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		for(ll i=0;i<n;i++)
			cin>>b[i];
		
		vector<ll> c{0,0,0,0};
		// ll ans1 = INT_MAX;
		ll temp1 = fun(b,a[0]);
		ll temp2 = fun(b,a[n-1]);
		ll temp3 = fun(a,b[0]);
		ll temp4 = fun(a,b[n-1]);
		
		ll ans1 = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
		ll ans2 = abs(a[0]-b[n-1])+abs(a[n-1]-b[0]);
		ll ans3 = abs(a[0]-b[0])+temp2+temp4;
		ll ans4 = abs(a[n-1]-b[n-1])+temp1+temp3;
		ll ans5 = abs(a[0]-b[n-1])+temp2+temp3;
		ll ans6 = abs(a[n-1]-b[0])+temp1+temp4;
		ll ans7 = temp1+temp2+temp3+temp4;
		ll ans = min(ans1,ans2);
		ans = min(ans,ans3);
		ans = min(ans,ans4);
		ans = min(ans,ans5);
		ans = min(ans,ans6);
		ans = min(ans,ans7);
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
