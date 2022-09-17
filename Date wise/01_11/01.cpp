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
	
	// ll t;
	// cin>>t;
	// while(t--)
	// {
	// 	int n,k;
	// 	cin>>n>>k;
	// 	string s;
	// 	cin>>s;
	// 	vector<int> v(26,0);
	// 	for(ll i=0;i<n;i++)
	// 		v[s[i]-'a']++;
	// 	int pair = 0;
	// 	for(int i=0;i<26;i++)
	// 		pair += v[i]/2;
	// 	ll l=1;
	// 	ll r=n/k+1;
	// 	ll ans = 1;
	// 	// cout<<pair<<endl;
	// 	while(l+1<r)
	// 	{
	// 		ll mid = l+(r-l)/2;
	// 		// cout<<l<<" "<<r<<" "<<mid<<endl;
	// 		if(pair >= (mid/2)*k)
	// 		{
	// 			ans = max(mid,ans);
	// 			// cout<<ans<<endl;
	// 			l = mid;
	// 		}
	// 		else
	// 			r = mid;
	// 	}
	// 	cout<<ans<<endl;

	// }
	int x=1;
	cout<<~x<<endl;
	cout<<(~x-x>>1)<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
