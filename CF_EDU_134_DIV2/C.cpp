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
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<ll> b(n);
		for(int i=0;i<n;i++)
			cin>>b[i];
		ll mn = a[0];
		ll mx = a[n-1];
		vector<ll> mnans(n);
		vector<ll> mxans(n);
		vector<ll> low(n);
		for(int i=0;i<n;i++)
		{
			ll idx=lower_bound(all(b),a[i])-b.begin();
			low[i]=idx;
		}
		for(ll i=0;i<n;i++)
		{
			ll idx=low[i];
			if(idx==n-1)
				mnans[i]=b[idx]-a[i];	
			else
				mnans[i]=min(b[idx]-a[i],b[idx+1]-a[i]);
		}
	
	
		vector<ll> v;
		for(ll i=0;i<n;i++)
		{
			if(a[i]>b[i-1])
				v.push_back(i);
		}
	
	    for(ll i=0;i<n;i++)
        {
            ll idx=upper_bound(all(v),i)-v.begin();
            if(idx==v.size())
            {
                mxans[i]=b[n-1]-a[i];
            }
            else
            {
                mxans[i]=b[v[idx]-1]-a[i];
            }
        }
		for(auto i:mnans)
			cout<<i<<" ";
		cout<<endl;
		for(auto i:mxans)
			cout<<i<<" ";
		cout<<endl;

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
