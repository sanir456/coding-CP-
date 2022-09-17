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
		ll a,b,n;
		cin>>a>>b>>n;
		if(a==b)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if((a^b)<n)
		{
			cout<<1<<endl;
			continue;
		}
		vector<int> v(30,0);
		int mx=0;
		for(int i=0;i<30;i++)
		{
			if(((a>>i)&1)!=((b>>i)&1))
			{
				v[i]=1;
				mx=i;
			}
		}
		// cout<<mx<<" ";
		if(pow(2,mx)>=n)
		{
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		int temp=0;
		for(int i=29;i>=0;i--)
		{
			if(v[i]==0) continue;
			if(temp+pow(2,i)<n)
			{
				temp+=pow(2,i);
			}
			else
			{
				ans++;
				temp=pow(2,i);
			}
		}
		if(temp>0) ans++;
		cout<<ans<<endl;
		
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
