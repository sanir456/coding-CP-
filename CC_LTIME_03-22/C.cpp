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


void bfs(ll t,queue<ll>& q,vector<bool>& f,ll& c,vector<vector<ll>> edge,vector<bool>& in)
{
	if(q.empty())
		return;
	while(t-- and !q.empty())
	{
		queue<ll> nq=q;
		ll l = nq.size();
		// cout<<" length: "<<l<<endl;
		// if(c<=0)
		// 	break;
		while(l-- and !nq.empty())
		{
			ll w = nq.front();
			nq.pop();
			f[w]=true;
			c--;
			// if(c<=0)
			// 	break;
			for(auto i : edge[w])
			{
				if(!f[i] and !in[i])
				{	
					nq.push(i);
					in[i]=true;
				}
			}
		}
		q=nq;		
	}
}
void print(queue<ll> q)
{
	while(!q.empty())
	{
		ll a = q.front();
		q.pop();
		cout<<a<<" ";
	}
	cout<<endl;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,m,q;
	cin>>n>>m>>q;
	// cout<<n<<m<<q;
	vector<vector<ll>> edge(n+1);
	for(ll i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	queue<ll> qu;
	vector<bool> f(n+1,false);
	vector<bool> in(n+1,false);
	ll c=n;
	while(q--)
	{
		// cout<<q<<" "<<c<<" ";
		// print(qu);
			
		// cout<<q<<endl;
		ll t,a;
		cin>>t>>a;
		if(t==1)
		{
			if(!f[a])
			{
				f[a]=true;
				c--;
				if(c<=0)
					continue;
				for(auto i : edge[a])
				{
					if(!f[i] and !in[i])
					{
						qu.push(i);
						in[i]=true;
					}
				}
				
			}
		}
		else if(t==2)
		{
			bfs(a,qu,f,c,edge,in);
		}
		else
		{
			if(f[a])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
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
