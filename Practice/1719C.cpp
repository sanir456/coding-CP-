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
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<ll> mx(n);
		mx[0]=v[0];
		for(int i=1;i<n;i++)
			mx[i]=max(v[i],mx[i-1]);
		while(q--)
		{
			ll i,k;
			cin>>i>>k;
			if(mx[i-1]!=v[i-1] or i>k+1)
			{
				cout<<0<<endl;
				continue;
			}
			ll idx = upper_bound(mx.begin(),mx.end(),mx[i-1])-mx.begin();
			// cout<<idx<<" ";
			if(idx==n)
			{
				cout<<k-max(i-2,0ll)<<endl;
			}
			else
			{
				cout<<min(k-max(i-2,0ll),idx-max(i-2,0ll)-1)<<endl;
			}
			
		}	
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
