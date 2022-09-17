#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TC(t) while(t--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define FOR(a,b,c) for(ll(a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll(a)=(b);(a)<=(c);++(a))
#define FORED(a,b,c) for(ll(a)=(b);(a)>=(c);--(a))
#define FOREACH(a,b) for(auto&(a):(b))

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("G:/Personal/CP/input.txt", "r", stdin);
	freopen("G:/Personal/CP/output.txt", "w", stdout);
	#endif 
}

ll util(string s,ll l,ll r,char c)
{
	ll ans = 0;
	while(l<r)
	{
		// cout<<l<<" "<<r<<endl;
		if(s[l]==s[r])
		{
			l++;
			r--;
			continue;
		}
		if(s[l]==s[r-1] && s[r]==c)
		{
			l++;
			r-=2;
			ans++;
		}
		else if(s[l+1]==s[r] && s[l]==c)
		{
			l+=2;
			r--;
			ans++;
		}
		else
			return -1;
	}
	return ans;

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
		string s;
		cin>>s;
		ll ans = INT_MAX;
		ll c = 'a';
		for(ll i=0;i<26;i++)
		{
			ll l=0;
			ll r=n-1;
			ll temp = 0;
			while(l<r)
			{
				if(s[l]==s[r])
				{	
					l++;
					r--;
				}
				else if(s[l]==(c+i))
				{
					l++;
					temp++;
				}
				else if(s[r]==(c+i))
				{
					r--;
					temp++;
				}
				else
				{
					temp = -1;
					break;
				}	
			}
			if(temp>=0)
			{
				ans = min(ans,temp);
			}
		}
		cout<<(ans==INT_MAX?-1:ans)<<endl;

		
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
