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
		ll p=0;
		ll ne=0;
		vector<ll> v;
		set<ll> s;
		ll temp;
		map<ll,ll> m;
		bool zero=false;
		for(ll i=0;i<n;i++)
		{
			cin>>temp;
			if(temp>0)
				p++;
			else if(temp<0)
				ne++;
			else
			{
				zero=true;
				s.insert(0);
				continue;
			}
			m[temp]++;
			if(m[temp]<3)
				v.push_back(temp);
			s.insert(temp);
			
		}
		if(p>2 or ne>2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		bool ok=true;
		if(zero) v.push_back(0);
		n=v.size();
		for(ll i=0;i<n-2 and ok;i++)
		{
			for(ll j=i+1;j<n-1 and ok;j++)
			{
				for(ll k=j+1;k<n and ok;k++)
				{
					if(s.find(v[i]+v[j]+v[k])==s.end())
					{
						ok=false;
					}
				}
			}
		}
		
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
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
