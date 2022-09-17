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


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int n;

void find_paths(vector<vector<int> >& paths,vector<int>& path,vector<int> parent[],int n, int u)
{
	//path find
    if (u == -1) {
        paths.push_back(path);
        return;
    }
 
 	//recursive call to find start node from each parent node
    for (int par : parent[u]) {
        path.push_back(u);
        find_paths(paths, path, parent,n, par);
        path.pop_back();
    }
}


void bfs(vector<int> adj[],vector<int> parent[],int n, int start)
{
    vector<int> dist(n, INT_MAX);
 
    queue<int> q;
 
    q.push(start);
    parent[start] = { -1 };
    dist[start] = 0;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
 
                //remove all other parent if new sortest distance parent is found
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1) {
 
                // other parent foun with same shortest distance
                parent[v].push_back(u);
            }
        }
    }
}


void print_paths(vector<int> adj[],int start, int end)
{
    vector<vector<int> > paths;
    vector<int> path;
    vector<int> parent[n];
 
    //find shortest node from s to each with listing parent node
    bfs(adj, parent, n, start);
 
    // find all sortest path from s to t
    find_paths(paths, path, parent, n, end);
 
    if(paths.size()==0)
    {
    	cout<<"NOT POSSIBLE";
    	return;
    }

    for (auto v : paths) {
 
        //reverse list buz it stort node from t to s
        reverse(v.begin(), v.end());
 
        for (int u : v)
            cout << u << " ";
        cout << endl;
    }
}
 


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	cin>>n;
	int e;
	cin>>e;
	vector<int> g[n];;
	for(int i=0;i<e;i++)
	{
		int s,t;
		cin>>s>>t;
		g[s].push_back(t);
		g[t].push_back(s);
	}
	
	int s,t;
	cin>>s>>t;
	
	print_paths(g,s,t);
	

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
