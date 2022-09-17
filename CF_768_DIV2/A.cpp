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
		ll m1=INT_MIN;
		ll m2=INT_MIN;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			m1 = max(m1,a[i]);
		}
		vector<ll> b(n);
		for(ll i=0;i<n;i++)
		{
			cin>>b[i];	
			m2 = max(m2,b[i]);
		}
		ll ans = INT_MAX;	
		if(m1>m2)
		{
			m2 = INT_MIN;
			for(ll i=0;i<n;i++)
			{
				if(a[i]!=m1 and b[i]>a[i])
					swap(a[i],b[i]);
				m2 = max(m2,b[i]);
			}

		}
		else
		{
			m1 = INT_MIN;
			for(ll i=0;i<n;i++)
			{
				if(b[i]!=m2 and a[i]>b[i])
					swap(a[i],b[i]);
				m1 = max(m1,a[i]);
			}
		}
		cout<<m1*m2<<endl;
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
