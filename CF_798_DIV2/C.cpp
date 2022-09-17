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

vector<vector<int>> g(300005);
int ch[300005],dp[300005];
 
void dfs(int p, int q)
{
    ch[p]=1,dp[p]=0; int s=0;
    for (auto it : g[p]) if (it!=q)
    {
        dfs(it,p); s+=dp[it];
        ch[p]+=ch[it];
    }
    for (auto it : g[p]) if (it!=q)
    {
        dp[p]=max(dp[p],s-dp[it]+ch[it]-1);
    }
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
 
        dfs(1,0);
        cout<<dp[1]<<"\n";
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
