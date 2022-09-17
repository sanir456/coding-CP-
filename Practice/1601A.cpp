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
		vector<int> v(n);
		vector<int> b(32,0);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			for(ll j=0;j<32;j++)
			{
				if(v[i]>>j & 1)
					b[j]++;
			}
		}
		cout<<1<<" ";
		for(ll k=2;k<=n;k++)
		{
			bool ok = true;
			for(ll i = 0;i<32 and ok;i++)
			{
				if(b[i]%k!=0)
					ok = false;
			}
			if(ok) cout<<k<<" ";
		}
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
