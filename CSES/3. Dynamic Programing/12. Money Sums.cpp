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
	
	int n;
	cin>>n;
	vector<int> v(n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
	dp[0][0]=true;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==0) continue;
			if(j==0) dp[i][j]=true;
			else
			{
				if(v[i-1]<=j)
					dp[i][j]=dp[i-1][j] or dp[i-1][j-v[i-1]];
				else
					dp[i][j]=dp[i-1][j];		
			}
			if(i==n and dp[i][j] and j!=0)
				ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=sum;i++)
	{
		if(dp[n][i])
			cout<<i<<" ";
	}
	cout<<endl;

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
