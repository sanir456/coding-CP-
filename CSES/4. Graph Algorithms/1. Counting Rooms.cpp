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


void dfs(int i,int j,vector<string>& g,vector<vector<int>>& vis)
{
	vis[i][j]=1;
	vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
	for(auto d:dir)
	{
		int x=i+d[0];
		int y=j+d[1];
		if(x>=0 and x<g.size() and y>=0 and y<g[0].size() and g[x][y]=='.' and vis[x][y]==0)
			dfs(x,y,g,vis);
	}
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll r,c;
	cin>>r>>c;
	vector<string> g(r);
	for(int i=0;i<r;i++)
		cin>>g[i];
	vector<vector<int>> vis(r,vector<int>(c,0));
	int ans=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(g[i][j]=='.' and vis[i][j]==0)
			{
				ans++;
				dfs(i,j,g,vis);
			}
		}
	}
	cout<<ans<<endl;
	

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
