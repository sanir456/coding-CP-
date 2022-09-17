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
	
	ll n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	string p = "abc";
	ll ans = 0;
	for(ll i = 0;i<n-2;i++)
		if(p.compare(s.substr(i,3))==0)
			ans++;
	while(q--)
	{
		ll pos;
		char c;
		cin>>pos>>c;
		

		if(p.compare(s.substr(pos-1,3))==0)
			ans--;
		else if(pos>1 and p.compare(s.substr(pos-2,3))==0)
			ans--;
		else if(pos>2 and p.compare(s.substr(pos-3,3))==0)
			ans--;

		s[pos-1]=c;
		if(c == 'b')
			pos--;
		else if(c=='c')
			pos-=2;
		
		if(pos>0 and p.compare(s.substr(pos-1,3))==0)
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
