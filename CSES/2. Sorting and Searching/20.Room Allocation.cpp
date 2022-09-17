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

bool comp(vector<ll>& i,vector<ll>& j)
{
	if(i[0]<j[0])
		return true;
	else if(i[0]==j[0])
	{
		if(i[1]<j[1])
			return true;
	}	
		
	return false;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	ll n;
	cin>>n;
	vector<vector<ll>> v;
	map<ll,ll> e;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v.push_back({x,0,i});
		v.push_back({y,1,i});
		e[i]=y;			
	}
	sort(all(v),comp);
	
	vector<ll> a;
	a.push_back(1);
	map<ll,ll> m;
	priority_queue<pair<ll,ll>> q;
	ll r = 2;
	for(auto i:v)
	{
		
		while(!q.empty() and -1*q.top().first<i[0])
		{
			pair<ll,ll> w = q.top();
			q.pop();
			a.push_back(m[w.second]);
		}
		
		if(i[1]==0)
		{
			if(a.size()==0)
			{
				m[i[2]]=r;
				r++;	
			}
			else
			{
				m[i[2]]=a.back();
				a.pop_back();
			}
			// while(!q.empty() and -1*q.top().first==i[0])
			// {
			// 	pair<ll,ll> w = q.top();
			// 	q.pop();
			// 	a.push_back(m[w.second]);
			// }
			q.push({e[i[2]]*-1,i[2]});
			 
		}
		else
		{
			while(!q.empty() and -1*q.top().first==i[0])
			{
				pair<ll,ll> w = q.top();
				q.pop();
				a.push_back(m[w.second]);
			}
		}
		// cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<q.size()<<endl;
		
	}	
	
	cout<<r-1<<endl;
	for(ll i=0;i<n;i++)
	{
		cout<<m[i]<<" ";
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
