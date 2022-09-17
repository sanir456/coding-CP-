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

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	ll t;
	cin>>t;
	while(t--)
	{
		ll n, m, i, j, k;
    	cin>>n;
    	ll g[105][105]={};
    	vector<string> Rv;
        map<string, ll> R;
        string x, y;
        for(i = 0; i < 105; i++)
            for(j = 0; j < 105; j++)
                g[i][j] = 0;
        ll idx = 0;
        for(i = 0; i < n; i++) {
            cin>>m;
            ll pre = idx;
            for(j = 0; j < m; j++) {
                cin >> x;
                R[x] = idx;
                Rv.push_back(x);
                idx++;
            }
            for(j = pre; j < idx-1; j++)
                g[j][j+1] = 1;
        }

 		cin>>m;
        while(m--) {
            cin >> x >> y;
            g[R[x]][R[y]] = 1;
        }
        for(k = 0; k < idx; k++)
            for(i = 0; i < idx; i++)
                for(j = 0; j < idx; j++)
                    g[i][j] |= g[i][k]&g[k][j];

		string res = "";
        int cnt = 0;
        for(i = 0; i < idx; i++)
            for(j = i+1; j < idx; j++)
                if(g[i][j] == 0 && g[j][i] == 0) {
                    cnt++;
                    if(cnt <= 2) {
                        res = res+"("+Rv[i]+","+Rv[j]+") ";
                    }
                }
        if(cnt) 
            cout << res << endl;
        else
        	cout<<"NO"<<endl;
	}
	return 0;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
