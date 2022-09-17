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

// not solve

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
		for(ll i=0;i<n;i++)
			cin>>v[i];
		ll s = 0;
		vector<ll> v1(n,0);
		for(ll i=0;i<n;i++)
		{
			s+=v[i];
			if(s<=0)
			{
				if(v[i]==0)
					v1[i]=0;
				else
					v1[i]=-1;
				s=0;
			}
			else
				v1[i]=1;
			
			
		}
		reverse(all(v));
		vector<ll> v2(n);
		s=0;
		for(ll i=0;i<n;i++)
		{
			s+=v[i];
			if(s<=0)
			{
				if(v[i]==0)
					v2[i]=0;
				else
					v2[i]=-1;
				s=0;
			}
			else
				v2[i]=1;
			
		}
		ll ans = 0;
		reverse(all(v2));
		for(auto i:v1)
			cout<<i<<" ";
		cout<<endl;
		for(auto i:v2)
			cout<<i<<" ";
		cout<<endl;
		for(ll i=0;i<n;i++)
		{

			if(max(v1[i],v2[i])==0)
				continue;
			if(max(v1[i],v2[i])>0)
				ans++;
			else 
				ans--;
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
