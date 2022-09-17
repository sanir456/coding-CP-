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

void update(int i,int j,int value,vector<vector<int>>& fen)
{
	for(;i<fen.size();i=i+(i&(-i)))
	{
		for(int jj=j;jj<fen[0].size();jj=jj+(jj&(-jj)))
		{
			fen[i][jj]+=value;
		}
	}
}

int query(int i,int j,vector<vector<int>>& fen)
{
	int sum=0;
	for(;i>0;i=i-(i&(-i)))
	{
		for(int jj=j;jj>0;jj=jj-(jj&(-jj)))
		{
			sum+=fen[i][jj];
		}
	}
	return sum;
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	vector<vector<int>> fen(n+1,vector<int>(m+1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>v[i][j];
			update(i+1,j+1,v[i][j],fen);
		}
	}
	cout<<query(n,m,fen)-query(n-1,m-1,fen)<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}


#define m (int)(1e9+7)
ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b)
}

ll power(ll a,ll b){
	ll ans = 1;
	while(b>0)
	{
		if(b & 1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

ll modInv(ll a,ll m){
	return power(a,m-2,m);
}