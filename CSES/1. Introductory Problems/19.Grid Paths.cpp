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

const int N = 7;

int ans;
string c;
bool vis[N+1][N+1];

bool inbounds(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

void dfs(int x, int y, int i){
    if(i == N*N-1 || (x == N && y == 1)){
        ans += (i == N*N-1 && (x == N && y == 1));
        return;
    }

    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;

    vis[x][y] = true;
    if(c[i] == 'D' || c[i] == '?')
        if(inbounds(x+1, y) && !vis[x+1][y])
            dfs(x+1, y, i+1);
    if(c[i] == 'U' || c[i] == '?')
        if(inbounds(x-1, y) && !vis[x-1][y])
            dfs(x-1, y, i+1);
    if(c[i] == 'R' || c[i] == '?')
        if(inbounds(x, y+1) && !vis[x][y+1])
            dfs(x, y+1, i+1);
    if(c[i] == 'L' || c[i] == '?')
        if(inbounds(x, y-1) && !vis[x][y-1])
            dfs(x, y-1, i+1);
    vis[x][y] = false;
}


int main(){
    time_t start, end;
    time(&start);
    FAST_IO
    init_code();
    

    cin>>c;
    dfs(1,1,0);
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
