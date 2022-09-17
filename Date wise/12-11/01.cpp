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

#define mod (int)(1e9+7)

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
	// cout<<"sani";
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<int> v(n);
		ll c=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]==1)
				c++;
		}
		if(c==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(c%3!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		ll s,m,e;
		ll i=0,temp=1;
		while(v[i]!=1)i++;
		s=i;
		i++;
		while(temp!=c/3) 
		{
			if(v[i]==1) temp++;
			i++;
		}
		while(v[i]!=1)i++;
		m=i;
		i++;
		temp=1;
		while(temp!=c/3) 
		{
			if(v[i]==1) temp++;
			i++;
		}
		while(v[i]!=1)i++;
		e=i;

		ll a	s = 0;
		while(e<n && v[s]==v[m] && v[m]==v[e])
		{
			ans=((ans*2)%mod+v[e])%mod;
			s++;
			m++;
			e++;
		}
		if(e==n)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
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
