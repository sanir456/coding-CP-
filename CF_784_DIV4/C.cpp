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
		vector<ll> v(n);
		ll ee=0,eo=0,oe=0,oo=0,o=0,e=0;
		for(ll i=1;i<=n;i++)
		{
			ll temp;
			cin>>temp;
			if(i%2)
			{
				
				if(temp%2)
				{
					oo++;
					o++;
				}
				else
				{
					oe++;
					e++;
				}
			}
			else
			{
				
				if(temp%2)
				{
					eo++;
					o++;
				}	
				else
				{
					ee++;
					e++;
				}
			}
		}
		
		if((o==n) || (e==n) ||(oo + ee == n) || (oe + eo==n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
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
