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
		map<ll,ll> m;
		ll sum = 0;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			m[temp]++;
			sum += temp;
		}			
		queue<ll> q;
		q.push(sum);
		ll s = 0;
		while(s!=n-1)
		{
			ll a = q.front();
			q.pop();
			if(m.find(a)!=m.end() and m[a]>0)
				m[a]--;
			else
			{
				s++;
				if(a%2==0)
				{
					q.push(a/2);
					q.push(a/2);					
				}
				else
				{
					q.push(a/2);
					q.push((a+1)/2);
				}
			}
		}
		bool ok = true;
		while(!q.empty())
		{
			ll a = q.front();
			q.pop();
			if(m.find(a)!=m.end() and m[a]>0)
				m[a]--;
			else
			{
				ok = false;
				break;
			}
		}
		for(auto i:m)
		{
			if(i.second>0)
			{
				ok = false;
				break;
			}
		}
		if(ok)
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
