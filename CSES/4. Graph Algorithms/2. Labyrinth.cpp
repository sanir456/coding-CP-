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

int vis[1000005]={0};
vector<int> adj[1000005];
int par[1000005];
queue<int> q;

void bfs(int s)
{
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(auto i:adj[s])
		{
			if(vis[i]) continue;
			vis[i]=vis[s]+1;
			par[i]=s;
			q.push(i);
		}
	}
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll r,c;
	cin>>r>>c;
	vector<vector<char>> g(r,vector<char>(c));
	int st;
	int ed;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int z=i*c+j;
			cin>>g[i][j];
			if(g[i][j]=='#') continue;
			if(g[i][j]=='A') st=z;
			if(g[i][j]=='B') ed=z;
			if(i>=1 and g[i-1][j]!='#') adj[z].push_back(z-c),adj[z-c].push_back(z);
			if(j>=1 and g[i][j-1]!='#') adj[z].push_back(z-1),adj[z-1].push_back(z);

 		}
	}
	bfs(st);
	if(vis[ed]==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	vector<int> ans;
	int i=ed;
	while(i!=st)
	{
		ans.push_back(i);
		i=par[i];
	}
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	string s="";
	int x=st/c;
	int y=st%c;
	for(int i=ans.size()-1;i>=0;i--)
	{
		int x1=ans[i]/c;
		int y1=ans[i]%c;
		if(x==x1)
			s+=(y>y1)?'L':'R';
		else
			s+=(x>x1)?'U':'D';
		x=x1;
		y=y1;
	}
	cout<<s<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
