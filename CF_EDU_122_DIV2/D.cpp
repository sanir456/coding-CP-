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
ll dfs(vector<ll> op,ll k,ll n,vector<ll> b,vector<ll> c)
{
	ll i, w;
    vector<ll> K(k + 1,0);

	
	for(i = 1; i <= n; i++)
    {
        for(w = k; w >= op[b[i-1]]; w--)
        {
			if (op[b[i-1]] <= w)
                K[w] = max(c[i - 1]+K[w - op[b[i - 1]]],K[w]);
            
        }
    }
    return K[k];


}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	vector<ll> op(1001,INF);
	op[1]=0;
	for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= 1000) {
                op[i + i / j] = min(op[i + i / j], op[i] + 1);
            }
        }
    }
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;

    	k = min(k, 12 * n);
		vector<ll> b(n);
		for(ll i=0;i<n;i++)
			cin>>b[i];
		vector<ll> c(n);
		for(ll i=0;i<n;i++)
			cin>>c[i];
		// for(ll i=0;i<n;i++)
		// 	cout<<op[b[i]]<<" ";
		// cout<<endl;
		cout<<dfs(op,k,n,b,c)<<endl;

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
