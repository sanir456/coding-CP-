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

bool comp(vector<ll> &a, vector<ll> &b){
	
	if(a[0] != b[0]) return a[0] < b[0];
	
	if(a[1] == a[2]) return true;
	return false;
}
int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,k;
	cin>>n>>k;
	vector<vector<ll>> v(n,vector<ll>(3));
	v[0][0]=0;
	v[0][1]=0;
	v[0][2]=0;
	ll alice = 0;
	ll bob = 0;
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>v[i][0]>>v[i][1]>>v[i][2];
		if(v[i][1]==1)
			alice++;
		if(v[i][2]==1)
			bob++;
		sum += v[i][0]; 
	}
	if(alice<k or bob<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(v.begin(),v.end(),comp);
	for(ll i=0;i<n;i++)
		cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
	
	// vector<vector<ll>> dp(sum+1,vector<vector<ll>>(sum+1,0);
	ll a=0;
	ll b=0;
	ll i=0;
	for(i=0;i<n and (a<k or b<k);i++)
	{
		if(v[i][1]==1)
			a++;
		if(v[i][2]==1)
			b++;
	}
	ll ans = 0;
	if(a==k)
	{
		b=k;
		for(ll j=0;j<i and a>0 and b>0;j++)
		{
			if(v[j][1]==1)
			{
				ans+=v[j][0];
				a--;
				if(v[j][2]==1)
					b--;
			}
		}
		for(ll j=0;j<i and b>0;j++)
		{
			if(v[j][1]==0 and v[j][2]==1)
			{
				ans+=v[j][0];
				b--;
			}
		}
	}
	else
	{
		a=k;
		for(ll j=0;j<i and a>0 and b>0;j++)
		{
			if(v[j][2]==1)
			{
				ans+=v[j][0];
				b--;
				if(v[j][1]==1)
					a--;
			}
		}
		for(ll j=0;j<i and a>0;j++)
		{
			if(v[j][2]==0 and v[j][1]==1)
			{
				ans+=v[j][0];
				a--;
			}
		}
	}
	cout<<ans<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
