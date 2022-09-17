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
	freopen("F:/CP/Hacker Cup/Round 1/A/consecutive_cuts_chapter_2_input.txt", "r", stdin);
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
	for(int T=1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		vector<ll> b(n);
		for(ll i=0;i<n;i++)
		{
			cin>>b[i];
		}
		bool ok=true;
		for(ll i=0;i<n and ok;i++)
			if(a[i]!=b[i])
				ok=false;
		if(k==0)
		{
			if(ok)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
		if(k==1)
		{
			if(!ok)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
		if(n==2)
		{
			if(ok)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
			
		}
		ok = false;
		
		vector<ll> pat;
		for(auto i:b)
			pat.push_back(i);
		for(auto i:b)
			pat.push_back(i);
		vector<ll> dp(n);
		ll l=0;
		dp[0]=0;
		ll i=1;
		while(i<n)
		{
			if(a[i]==a[l])
			{
				l++;
				dp[i]=l;
				i++;
			}
			else
			{
				if(l!=0)
					l=dp[l-1];
				else
				{
					dp[i]=0;
					i++;
				}
				
			}
		}
		i=0;
		ll j=0;
		while((2*n-i)>=(n-j))
		{
			if(a[j]==pat[i])
			{
				j++;
				i++;
			}
			if(j==n)
			{
				ok=true;
				break;
			}		
			else if(i<2*n  and a[j]!=pat[i])
			{
				if(j!=0)
					j=dp[j-1];
				else
					i++;
			}		
		}
		if(ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


	
	
	return 0;
}
