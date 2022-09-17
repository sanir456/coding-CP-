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
		ll n,k;
		cin>>n>>k;
		k++;
		vector<ll> v(n);
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			v[i]=power(10,v[i]);
		}
		for(ll i = 0;i<n-1;i++)
		{
			ll temp = (v[i+1]/v[i])-1; 
			if(temp<k)
			{
				ans+=temp*v[i];
				k-=temp;
			}
			else
			{
				ans+=(k)*v[i];
				k=0;
			}
		}
		if(k>0)
			ans+=(k)*v[n-1];
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
