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
	
	  int n,m; cin>>n>>m;
    int l = 1;
    int ind[n+2] = {0}, a[n+1] = {0};
    ind[n+1] = n+1;
    for (int i = 1; i <= n; i++) {
		int x; cin>>x;
		ind[x] = i;
		a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
		if (l > ind[i]) 
		c++;
		l = ind[i];
    }
    while(m--) {
		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (ind[r-1] <= ind[r] && ind[r-1] > y) c++;
		if (ind[r-1] > ind[r] && ind[r-1] <= y) c--;
		if (ind[r] <= ind[r+1] && y > ind[r+1]) c++;
		if (ind[r] > ind[r+1] && y <= ind[r+1]) c--;		
		ind[r] = y;
		if (ind[s-1] <= ind[s] && ind[s-1] > x) c++;
		if (ind[s-1] > ind[s] && ind[s-1] <= x) c--;
		if (ind[s] <= ind[s+1] && x > ind[s+1]) c++;
		if (ind[s] > ind[s+1] && x <= ind[s+1]) c--;	
		ind[s] = x;
		cout<<c<<endl;
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
