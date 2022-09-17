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
	queue<int> q;
	par[1]=1;
	q.push(1);
	bool find=false;
	while(!q.empty() and !find)
	{
		int top=q.front();
		q.pop();
		for(auto i:adj[top])
		{
			if(par[i]==0)
			{
				par[i]=top;
				q.push(i);
				if(i==n)
				{
					find=true;
					break;
				}
			}
		}
	}
	if(par[n]==0)
		cout<<"IMPOSSIBLE"<<endl;
	else
	{
		vector<int> ans;
		int st=n;
		while(st!=1)
		{
			ans.push_back(st);
			st=par[st];
		}
		cout<<ans.size()+1<<endl;
		cout<<1<<" ";
		for(auto it=ans.rbegin();it!=ans.rend();it++)
			cout<<*it<<" ";
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
