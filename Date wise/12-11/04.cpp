#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


double EPS = 1e-9;
ll INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define x first
#define y second
#define mp make_pair
#define pb push_back


struct flow_graph{
    ll MAX_V,E,s,t;
    ll *cap,*to,*next,*last;
    bool *visited;
    
    flow_graph(ll V, ll MAX_E){
        MAX_V = V; E = 0;
        cap = new ll[2*MAX_E], to = new ll[2*MAX_E], next = new ll[2*MAX_E];
        last = new ll[MAX_V], visited = new bool[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(ll u, ll v, ll uv, ll vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
    
    ll dfs(ll v, ll f){
        if(v==t || f<=0) return f;
        if(visited[v]) return 0;
        visited[v] = true;
        for(ll e=last[v];e!=-1;e=next[e]){
            ll ret = dfs(to[e],min(f,cap[e]));
           if(ret>0){
               cap[e] -= ret;
               cap[e^1] += ret;
               return ret;
           }
       }
       return 0;
   }
   
   ll max_flow(ll source, ll sink){
       s = source, t = sink;
       ll f = 0,x;
       while(true){
           fill(visited,visited+MAX_V,false);
           x = dfs(s,INT_MAX);
           if(x==0) break;
           f += x;
       }
       return f;
   }
};


map<string, ll> myMap;
ll map_size;

ll getIndex(string name){
    if(myMap.find(name)==myMap.end())
        myMap[name] = ++map_size;
    return myMap[name];
}

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
	

 	ll t,n,m,k;
    string name1,name2;
    flow_graph G(2+100+200+200,100+2*100+100); 
    
    cin>>t;
    
    while(t--){
		G.clear();
		cin>>n;
		myMap.clear(); map_size = 0;
		for(ll i=0;i<n;i++){
		    cin>>name1;
		    G.add_edge(1+getIndex(name1),1,1);
		}
		cin>>m;
		for(ll i=0;i<m;++i){
		    cin>>name1>>name2;
		    G.add_edge(0,1+getIndex(name1),1);
		    G.add_edge(1+getIndex(name1),1+getIndex(name2),1);
		}
		cin>>k;
		
		for(ll i=0;i<k;++i){
		    cin>>name1>>name2;
		    G.add_edge(1+getIndex(name1),1+getIndex(name2),100);
		}
		
		cout<<m-G.max_flow(0,1)<<endl;
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
