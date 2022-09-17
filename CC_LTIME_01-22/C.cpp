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
ll power(ll a,ll b){
	if(b==0)
		return 1;
	ll p = power(a,b/2);
	p = (p*p);
	return (b%2==0)?p:(p*a);
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
		ll ans = 0;
		ll k = log2(n)+1;
		// cout<<" "<<k<<endl;
		ll temp = n;
		while(temp>0)
		{
			// ll l = power(2,log2(temp))-1;
			ll r = power(2,log2(temp));
			// cout<<r<<" "<<ans<<" ";
			ans += min((temp-r+1),r-1)*2*(power(2,log2(temp)+1)-1);
			temp = r - ((temp-r)+2);

			// while(r<=temp and l>0)
			// {
			// 	ans+=2*(l^r);
			// 	l--;
			// 	r++;
			// }
			// temp = l;
			
			
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
