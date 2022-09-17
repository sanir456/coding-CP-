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


//unsolved
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
		for(ll i=0;i<n;i++)
			cin>>v[i];	
		int a;
		int l;
		int r;
		int mx=0;
		int cnt=0;
		int cnd;
		int cl;
		for(int i=0;i<n;i++)
		{
			if(cnt==0)
			{
				cnt=1;
				cnd=v[i];
				// cout<<cnd<<" ";
				int temp=i-1;
				while(temp>=0 and v[temp]==cnd)
				{
					cnt++;
					temp--;
				}
				// cout<<cnt<<endl;
				cl=temp+1;;
			}
			else
			{
				if(v[i]==cnd)
					cnt++;
				else
					cnt--;
			}
			if(cnt>mx)
			{
				mx=cnt;
				a=cnd;
				l=cl;
				r=i;
			}
		}
		cout<<a<<" "<<l+1<<" "<<r+1<<endl;
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
