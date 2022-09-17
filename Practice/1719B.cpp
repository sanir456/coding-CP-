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
		if(k%4==0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		if(k%2==1)
		{
			for(int i=1;i<=n;i=i+2)
			{
				cout<<i<<" "<<i+1<<endl;
			}
		}
		else
		{
			int i=1;
			for(int j=2;j<=n;j=j+4)	
			{
				cout<<j<<" "<<i<<endl;	
				i=i+2;
			}
			for(int j=4;j<=n;j=j+4)
			{
				cout<<i<<" "<<j<<endl;
				i=i+2;
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
