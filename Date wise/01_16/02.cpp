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

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n = s.size();
		string ans;
		bool ok = true;
		for(ll i = n-1;i>0 and ok;i--)
		{
			ll t1 = s[i]-'0';
			ll t2 = s[i-1]-'0';
			t1 = t2+t1;
			if(t1>=10)
			{
				ans = s.substr(0,i-1) + (char)(t1/10+'0') + (char)(t1%10+'0') + s.substr(i+1,n-1-i);
				ok = false;
			}
		}

		if(ok)
		{
			ll t1 = s[1]-'0';
			ll t2 = s[0]-'0';
			t1 = t2+t1;
			ans = (char)(t1+'0')+s.substr(2,n-2);
			
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
