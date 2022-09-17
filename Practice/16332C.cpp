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
		ll a,b;
		cin>>a>>b;
		if((a|b)==b)
		{
			cout<<1<<endl;
			continue;
		}

		ll ans = abs(a-b);
		for(ll new_a=a;new_a<b;new_a++)
		{
			if((new_a|b)==b)
			{
				ans = min(ans,new_a-a+1);
				// cout<<"in ";
				break;
			}	
			else
			{
				for(ll i=1;i<32;i++)
				{
					ll a1 = new_a%(ll)pow(2,i);
					ll b1 = b%(ll)pow(2,i);
					// cout<<a1<<" "<<b1<<endl;
					if(a1>b1)
						ans = min(ans,new_a-a+a1-b1+(new_a|(b+a1-b1))-(b+a1-b1)+1);
					else
						ans = min (ans,new_a-a+b1-a1 + (b|(new_a+b1-a1))-b+1);
					// ans = min(ans,abs(a1-b1)+abs())
				}
			}
		}
		cout<<ans<<endl;


		// cout<<ans<<endl;
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
