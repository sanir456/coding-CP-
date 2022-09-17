#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define x first
// #define y second
// #define mp make_pair
// #define pb push_back

// #define m (int)(1e9+7)

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

// ll power(ll a,unsigned ll b,unsigned ll m){
// 	if(b==0)
// 		return 1;
// 	ll p = power(a,b/2,m)%m;
// 	p = (p*p)%m;
// 	return (y%2==0)?p:((p*a)%m);
// }

// ll modInv(ll a,ll m){
// 	return power(a,m-2,m);
// }


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
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> v(n);
		ll d1;
		cin>>d1;
		v[0]=d1;
		ll d2;
		cin>>d2;
		v[1]=d2;
		for(ll i=2;i<n;i++)
		{
			cin>>v[i];
			if(i%2==0)
				d1=gcd(d1,v[i]);
			else
				d2=gcd(d2,v[i]);
			// cout<<v[i]<<" ";
		}
		ll i;
		for(i=0;i<n-1;i++)
		{
			if(v[i]%d1==0 and v[i+1]%d1==0)
				break;
		}
		// cout<<i<<" ";
		if(i==n-1)
		{
			cout<<d1<<endl;
			continue;
		}
		i=0;
		for(i=0;i<n-1;i++)
		{
			if(v[i]%d2==0 and v[i+1]%d2==0)
				break;
		}
		// cout<<i<<" ";
		if(i==n-1)
			cout<<d2<<endl;
		else
			cout<<0<<endl;
		
		
		
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
