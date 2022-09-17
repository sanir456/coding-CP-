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
void google(int t) {cout << "Case #" << t << ": ";}

vector<ll> fact(ll n)
{
	vector<ll> f;
	// f.push_back(1);
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
				f.push_back(i);
			else
			{
				f.push_back(i);
				f.push_back(n/i);
			}
		}
	}
	return f;
}

int main(){
	
	
	ll t;
	cin>>t;
	for(ll j=1;j<=t;j++)
	{
		ll n;
		cin>>n;
		vector<ll> f = fact(n);
		ll ans = 0;
		for(auto i:f)
		{
			string s = to_string(i);
			if(s.size()==1)
			{
				ans++;
				// cout<<i<<" ";
			
			}
			else
			{
				ll l=0;
				ll r=s.size()-1;
				bool ok = true;
				while(l<r)
				{
					if(s[l]!=s[r])
					{
						ok=false;
						break;
					}
					l++;
					r--;
				}
				if(ok)
				{
					ans++;
					// cout<<i<<" ";
			
				}
			}
		}
		google(j);
		cout<<ans<<endl;
	}

	

	return 0;
}
