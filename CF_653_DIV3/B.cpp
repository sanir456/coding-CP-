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
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(n%3!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		
		ll temp = n;
		ll ans = 0;
		while(temp%3==0)
		{
			if(temp%6==0)
			{
				temp/=6;
				ans++;
			}
			else if(temp%3==0)
			{
				temp/=3;
				ans+=2;
			}
		}
		if(temp==1)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
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
