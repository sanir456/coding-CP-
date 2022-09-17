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

bool isValid(ll k,string s,ll q)
{
	ll a=0;
	ll b=0;
	for(ll i=0;i<k;i++)
	{
		if(s[i]=='a')
			a++;
		else
			b++;
	}	
	if(a<=q or b<=q)
		return true;
	for(ll i=k;i<s.size();i++)
	{
		if(s[i]=='a')
			a++;
		else
			b++;
		if(s[i-k]=='a')
			a--;
		else
			b--;
		if(a<=q or b<=q)
			return true;
	}
	return false;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	ll l=1;
	ll r=s.size();
	ll ans=1;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		
		if(isValid(mid,s,k))
		{
			l = mid+1;
			ans = max(ans,mid);
		}
		else
			r = mid-1;
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
