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
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a(n);
		map<ll,ll> m1;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			m1[a[i]]++;
		}
		ll ans=0;
		vector<ll> b(n);
		map<ll,ll> m2;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			if(m1[b[i]]>0)
			{
				m1[b[i]]--;
			}
			else
			{
				m2[b[i]]++;
			}
		}
		for(auto i:m1)
		{
			if(i.first>9 and i.second>0)
			{
				m1[to_string(i.first).size()]+=i.second;
				ans+=i.second;
			}
		}
		
		for(auto i:m2)
		{
			if(i.first>9 and i.second>0)
			{
				m2[to_string(i.first).size()]+=i.second;
				ans+=i.second;
			}
		}
		for(int i=2;i<10;i++)
		{
			ans+=abs(m1[i]-m2[i]);
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
