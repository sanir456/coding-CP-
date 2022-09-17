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

vector<vector<ll>> v;
void fun(vector<ll> c,ll n,ll i)
{
	// cout<<i<<endl;
	if(i==n)
	{
		// cout<<i<<endl;
		v.push_back(c);
		return;
	}
	else
	{
		ll a = 0;
		while(a!=3)
		{
			c.push_back(a);
			fun(c,n,i+1);
			c.pop_back();
			a++;
		}
	}
	return;


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
		vector<ll> c;
		fun(c,n,0L);
		ll ans = 0;
		

		for(vector<ll> i:v)
		{
			for(ll j=1;j<n-1;j++)
			{
				if((i[j-1]>i[j] && i[j]<i[j+1]) || (i[j-1]<i[j] && i[j]>i[j+1]))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		v.clear();
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
