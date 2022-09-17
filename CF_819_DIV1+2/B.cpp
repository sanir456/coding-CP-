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
		ll n,m;
		cin>>n>>m;
		
		if(m<n)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(m%n==0)
		{
			cout<<"Yes"<<endl;
			for(int i=0;i<n;i++)
				cout<<m/n<<" ";
			cout<<endl;
			continue;
		}
		ll r = m%n;
		ll q = m/n;
		if(n%2==0)
		{
			if(r%2==0 and r/2+q>0)
			{
				cout<<"yes"<<endl;
				cout<<r/2+q<<" "<<r/2+q<<" ";
				for(int i=2;i<n;i++)
					cout<<q<<" ";
				cout<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}	
		else
		{
			cout<<"Yes"<<endl;
			cout<<q+r<<" ";
			for(int i=1;i<n;i++)
				cout<<q<<" ";
			cout<<endl;
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
