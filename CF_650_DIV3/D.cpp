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
		string s;
		cin>>s;
		ll n;
		cin>>n;
		vector<ll> v(n);
		vector<ll> m(26,0);
		for(ll i=0;i<s.size();i++)
			m[s[i]-'a']++;
		for(ll i=0;i<n;i++)
			cin>>v[i];
		ll k=n;
		ll c=25;
		vector<ll> ans(n,0);
		while(k>0)
		{
			for(ll i=0;i<n;i++)
				cout<<v[i]<<" ";
			// cout<<endl;
			set<ll> idx;
			for(ll i=0;i<n;i++)
			{
				if(v[i]==0)
					idx.insert(i);
			}
			// cout<<k<<endl;
			while(m[c]<idx.size())
				c--;
			for(auto i:idx)
			{
				ans[i]=c;
				v[i]=-1;
				for(ll j=0;j<n;j++)
				{
					if(v[j]!=-1)
					{
						if(idx.find(j)==idx.end())
						{
							v[j]-=abs(j-i);
						}
					}
				}
			}
			cout<<(char)(c+'a')<<endl;
			c--;
			k-=idx.size();
		}
		string res="";
		for(auto i:ans)
			res = res + (char)(i+'a');
		cout<<res<<endl;		
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

