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
	
	int r,c;
	vector<string> g;
	for(int i=0;i<r;i++)
		cin>>g[i];
	vector<int> adj[r*c];
	queue<pair<int,int>> q;
	vector<int> par(r*c,0);
	int e;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int z=i*c+j;
			if(g[i][j]=='#') continue;
			if(g[i][j]=='M') q.push({z,0}),par[z]=z;			
			if(g[i][j]=='A') par[z]=z,e=z;
			if(i>=1 and g[i-1][j]!='#') adj[z].push_back(z-c),adj[z-c].push_back(z);
			if(j>=1 and g[i][j-1]!='#') adj[z-1].push_back(z),adj[z].push_back(z-1);
		}
	}
	q.push({e,1});
	int w=-1;
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		int x=p.first/c;
		int y=p.first%c;
		if((x==0 or x==r-1 or y==0 or y==c-1) and p.second==1)
		{
			w=p.first;
			break;	
		}
		q.pop();
		for(auto i:adj[p.first])
		{
			if(par[i]==0)
			{
				q.push({i,p.second});
				par[i]=p.first;
			}	
		}
	}
	if(w==-1)
		cout<<"NO"<<endl;
	else
	{
		string ans="";
		vector<int> path;
		int st=w;
		while(par[st]!=st)
		{
			path.push_back(st);
			st=par[st];
		}
		cout<<"YES"<<endl;
		int x=e/c;
		int y=e%c;
		for(int i=path.size()-1;i>=0;i--)
		{
			int x1=path[i]/c;
			int y1=path[i]%c;
			if(x==x1)
				ans+=(y>y1)?'L':'R';
			else
				ans+=(x>x1)?'U':'D';
			x=x1;
			y=y1;
		}
		cout<<ans.size()<<endl;
		cout<<ans<<endl;
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
