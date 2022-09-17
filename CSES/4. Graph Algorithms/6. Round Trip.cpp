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
	
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> par(n+1,0);
	bool find=false;
	int u=0,v=0;
	for(int i=1;i<=n and !find;i++)
	{
		if(par[i]==0)
		{
			queue<int> q;
			par[i]=i;
			q.push(i);
			while(!q.empty() and !find)
			{
				int top =q.front();
				q.pop();
				for(auto j:adj[top])
				{
					if(par[j]==0)
					{
						par[j]=top;
						q.push(j);
					}
					else if(j!=par[top])
					{
						u=j;
						v=top;
						find=true;
						break;
					}
				}
				
			}
		}
	}
	// cout<<u<<" "<<v<<endl;
	if(!find)
		cout<<"IMPOSSIBLE"<<endl;
	else
	{
		vector<int> ans1;
		vector<int> ans2;
		int st=u;
		while(par[st]!=st)
		{
			ans1.push_back(st);
			st=par[st];
		}
		ans1.push_back(st);
		st=v;
		while(par[st]!=st)
		{
			ans2.push_back(st);
			st=par[st];
		}
		ans2.push_back(st);
		int i=ans1.size();
		int j=ans2.size();
		while(ans1[i-1]==ans2[j-1])
		{
			i--;
			j--;
		}
		cout<<i+j+2<<endl;
		for(;i>=0;i--)
			cout<<ans1[i]<<" ";
		for(int i=0;i<=j;i++)
			cout<<ans2[i]<<" ";
		cout<<endl;
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
