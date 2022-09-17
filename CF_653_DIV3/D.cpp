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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			v[i]=(k-temp%k);
			if(v[i]==k)
				v[i]=0;
		}
		sort(v.begin(),v.end());
		ll i=0;
		vector<ll> temp = v;
		while(i<n and temp[i]==0)
		{
			i++;
		}
		for(i=i+1;i<n;i++)
		{
			if(v[i]==v[i-1])
			{
				temp[i]=temp[i-1]+k;
			}
		}
		ll ans = INT_MIN;
		for(ll i=0;i<n;i++)
		{
			ans = max(ans,temp[i]);
			// cout<<temp[i]<<" ";
		}
		// cout<<endl;
		if(ans!=0)
			ans++;
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
