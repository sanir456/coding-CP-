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
	
	vector<ll> v;
	for(ll i=10;i<1000;i++)
		if(i%7==0)
			v.push_back(i);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n%7==0)
		{
			cout<<n<<endl;
			continue;
		}
		if(n>=100)
		{
			ll ans=994;
			ll c=3;
			for(ll i=13;i<v.size();i++)
			{
				string s = to_string(n);
				string t = to_string(v[i]);
				ll temp = 0;
				for(ll j=0;j<3;j++)
					if(s[j]!=t[j])
						temp++;
				if(temp==1)
				{
					ans = v[i];
					break;
				}
				else if(temp<c)
				{
					ans = v[i];
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			ll ans=98;
			ll c=2;
			for(ll i=0;i<13;i++)
			{
				string s = to_string(n);
				string t = to_string(v[i]);
				ll temp = 0;
				for(ll j=0;j<2;j++)
					if(s[j]!=t[j])
						temp++;
				if(temp==1)
				{
					ans = v[i];
					break;
				}
				else if(temp<c)
				{
					ans = v[i];
				}
			}
			cout<<ans<<endl;
		}
		
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
