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
		vector<double> v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		if(n<3)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans = INT_MAX;
		for(ll i=0;i<n-1;i++)
		{
			for(ll j=i+1;j<n;j++)
			{
				double d=(v[j]-v[i])/(double)(j-i);
				ll l = i;
				ll r = j;
				vector<double> temp = v;
				ll c = 0;
				while(l>0)
				{
					if(c>ans)
						break;
					if(temp[l-1]+d != temp[l])
					{
						temp[l-1] = temp[l]-d;
						c++;
					}
					l--;
				} 
				l=i;
				while(l<r)
				{

					if(c>ans)
						break;
					if(temp[l+1]-d != temp[l])
					{
						temp[l+1]=temp[l]+d;
						c++;
					}
					l++;
				}
				while(r<n-1)
				{
					
					if(c>ans)
						break;
					if(temp[r+1]-d != temp[r])
					{
						temp[r+1]=temp[r]+d;
						c++;
					}
					r++;

				}
				ans = min(ans,c);
			}
		}
		cout<<min(ans,n-1)<<endl;

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
