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
		map<char,ll> m;
		for(int i=0;i<n;i++)
			m[s[i]]++;
		vector<pair<ll,char>> v;
		for(auto i:m)
			 v.push_back({i.second,i.first});
		sort(all(v));
		reverse(all(v));
		queue<pair<ll,char>> q;
		for(auto i:v)
			q.push(i);
		string ans="";
		if(q.size()==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		while(q.size()!=2)
		{
			pair<ll,char> p =q.front();
			// cout<<p.first<<" "<<p.second<<endl;
			q.pop();
			ans.push_back(p.second);
			p.first=p.first-1;
			if(p.first!=0)
				q.push(p);
		}
			
		pair<ll,char> p1=q.front();
		q.pop();
		pair<ll,char> p2=q.front();
		q.pop();
		// cout<<p1.first<<" "<<p2.first<<endl;
		if(p1.first==p2.first and p1.first==1)
		{
			ans.push_back(p1.second);
			ans.push_back(p2.second);
			
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else if(p1.first==p2.first+1  and ans.size()>1)
		{
			ll n=ans.size();
			// cout<<ans<<endl;
			if(ans[n-2]!=p1.first)
			{
				ans.push_back(p1.second);
				swap(ans[n],ans[n-1]);
				ans.push_back(p1.second);
				ans.push_back(p2.second);
				cout<<"YES"<<endl;
			    cout<<ans<<endl;
			}	
			else
			{
				cout<<"NO"<<endl;
				continue;
			}	
			
		}
		else
		{
			cout<<"NO"<<endl;
			continue;
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
