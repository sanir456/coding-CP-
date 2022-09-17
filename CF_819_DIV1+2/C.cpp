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
		string s;
		cin>>s;
		stack<ll> st;
		
		ll ans=1;
		ll temp=0;
		for(int i=0;i<2*n-1;i++)
		{
			if(s[i]=='(' and s[i+1]==')')
			{
				temp++;	
			}
		}
		cout<<ans+n-temp<<endl;
		// vector<ll> vis(2*n,0);
		// for(ll i=0;i<2*n;i++)
		// {
		// 	if(vis[i]==1)
		// 		continue;
		// 	ans++;
		// 	queue<ll> q;
		// 	q.push(i);
		// 	vis[i]=1;
		// 	while(!q.empty())
		// 	{
		// 		ll size=q.size();
		// 		while(size--)
		// 		{
		// 			ll top = q.front();
		// 			q.pop();
		// 			for(auto j:v[top])
		// 			{
		// 				if(vis[j]==0)
		// 				{
		// 					vis[j]=1;
		// 					q.push(j);
		// 				}	
		// 			}
		// 		}		
		// 	}
		// }
		// cout<<ans<<endl;s
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
