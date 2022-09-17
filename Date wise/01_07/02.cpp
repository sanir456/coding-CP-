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

bool isValid(vector<ll> v1,vector<ll> v2,ll k,ll n)
{
	v1[100]+=k;
	v2[0]+=k;
	ll a = (n+k)/4;
	ll sum1 = 0;
	for(int i=0;i<101;i++)
	{
		if(a!=0)
		{
			if(v1[i]<a)
				a-=v1[i];
			else
			{
				v1[i]-=a;
				a=0;
				sum1+=(v1[i]*i);
			}
		}
		else
			sum1+=(v1[i]*i);
	}


	ll sum2 = 0;
	a = (n+k)/4;
	for(int i=0;i<101;i++)
	{
		if(a!=0)
		{
			if(v2[i]<a)
				a-=v2[i];
			else
			{
				v2[i]-=a;
				a=0;
				sum2+=(v2[i]*i);
			}
		}
		else
			sum2+=(v2[i]*i);
	}
	// cout<<sum1<<" "<<sum2<<endl;
	return sum1>=sum2;
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
		vector<ll> v1(101,0);
		vector<ll> v2(101,0);
		ll sum1=0;
		ll sum2=0;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			sum1+=temp;
			v1[temp]++;
		}

		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			sum2+=temp;
			v2[temp]++;
		}		
		// if(sum1>=sum2)
		// {
		// 	cout<<0<<endl;
		// 	continue;
		// }
		ll l=0;
		ll r=INF;
		ll ans = INT_MAX;
		while(l<=r)
		{
			ll mid = l + (r-l)/2;
			vector<ll> temp1 = v1;
			if(isValid(v1,v2,mid,n))
			{
				ans=min(ans,mid);
				r = mid-1;
			}
			else
				l = mid+1;
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
