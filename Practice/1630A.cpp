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
		ll n,k;
		cin>>n>>k;
		if(n==k+1)
		{	
			if(n==4)
			{
				cout<<-1<<endl;
				continue;
			}
			cout<<n-1<<" "<<n-2<<endl;
			cout<<n-3<<" "<<1<<endl;
			cout<<0<<" "<<2<<endl;
			
			for(ll i=3;i<n/2;i++)
			{
				if(i==k or i==(n-1-k))
					continue;
				cout<<i<<" "<<(n-1-i)<<endl;
			}
			continue;
		}
		cout<<0<<" "<<(n-1-k)<<endl;
		if(k!=0)
			cout<<k<<" "<<n-1<<endl;
		for(ll i=1;i<n/2;i++)
		{
			if(i==k or i==(n-1-k))
				continue;
			cout<<i<<" "<<(n-1-i)<<endl;
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
