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
void google(int t) {cout << "Case #" << t << ": ";}

double area(double r)
{
	return 3.14159265*r*r;
}

int main(){
	
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		// cout<<i;
		double r;
		double a,b;
		cin>>r>>a>>b;
		double ans = 0;
		while(area(r)>0.000001)
		{
			
			ans += area(r);
			r = r*a;
			if(area(r)>0.000001)
			{
				ans+=area(r);
				r=(ll)(r/b);
			}
			// cout<<r<<endl;
		}
		google(i);
		cout << fixed<< ans << setprecision(6)<<endl;
	}
	


	
		return 0;
}
