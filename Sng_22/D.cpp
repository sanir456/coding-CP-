
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

ll mod=(ll)(1e9+7);


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll x,y;
	cin>>x>>y;
	ll n;
	cin>>n;
	ll ans;
	ll z = (y-x)%mod;
	if(n==3)
		ans=z;
	else if(n==2)
		ans=y;
	else if(n==1)
		ans=x;
	else
	{
		ll d = n/3;
		if(n%3 == 2)
		{
			if(d%2==0)
				ans = y;
			else
				ans = -y;
		}
		else if(n%3==1)
		{
			if(d%2==0)
				ans=x;
			else
				ans = -x;
		}
		else
		{
			if(d%2==0)
				ans = -z;
			else
				ans = z;
		}
			
	}
	if(ans<0)
		cout<<ans+mod<<endl;
	else
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
