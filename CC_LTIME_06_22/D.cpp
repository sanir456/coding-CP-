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
		int n;
		cin>>n;
		vector<int> v(n+1);
		int x=0;
		for(int i=0;i<=n;i++)
			cin>>v[i];
			
		if(n%2==1)
		{
			for(int i=0;i<=n;i++)
				x=x^v[i];
			
			bool ok=true;
			for(int i=0;i<=n;i++)
			{
				if(v[i]==x and ok)
				{
				    ok=false;   
				}
				else
				{
					int temp=x^v[i];
					cout<<temp<<" ";
				}
			
			}
		
			cout<<endl;
		}
		else
		{
			for(int i=0;i<=n;i++)
			{
				x=x^v[i];
				if(x!=0) break;
			}
			bool ok=true;
			for(int i=0;i<=n;i++)
			{
				if(v[i]==x and ok)
				{
				    ok=false;   
				}
				else
				{
					int temp=x^v[i];
					cout<<temp<<" ";
				}
			
			}
		
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
