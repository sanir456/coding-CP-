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

	ll n,m;
	cin>>n>>m;
	// cout<<n<<" "<<m<<endl;
	bool ok = true;
	vector<vector<ll>> v(m,vector<ll>(2));
	for(ll i=0;i<m;i++)
	{
		cin>>v[i][0]>>v[i][1];
		if(v[i][0]>n or v[i][1]>n)
			ok = false;
	}
	if(!ok)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	ll a;
	if(v[0][0]==v[1][0] or v[0][0]==v[1][1])
		a = v[0][0];
	else if(v[0][1]==v[1][0] or v[0][1]==v[1][1])
		a = v[0][1];
	// cout<<a<<endl;
	ll i=2;
	while(i<m and (v[i][0]==a or v[i][1]==a))
		i++;
	if(i==m)
	{	
		cout<<"YES"<<endl;
		return 0;
	}
	ll b=-1;
	i++;
	if(v[i-1][0]==v[i][0] or v[i-1][0]==v[i][1])
		b = v[i-1][0];
	else if(v[i-1][1]==v[i][0] or v[i-1][1]==v[i][1])
		b = v[i-1][1];
	if(a==b)
	{
		i--;
		if(i<m and (v[i-1][0]==v[i][0] or v[i-1][0]==v[i][1]))
			b = v[i-1][0];
		else if(i<m and (v[i-1][1]==v[i][0] or v[i-1][1]==v[i][1]))
			b = v[i-1][1];
		
	}

	while(i<m and (v[i][0]==a or v[i][1]==a or v[i][0]==b or v[i][1]==b))
		i++;
	if(i==m)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
