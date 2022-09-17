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
	
		
	string s;
	cin>>s;
	
	int n=s.size();
	vector<vector<int>> dp(26,vector<int>(n,0));
	vector<int> ans[n];
	dp[s[0]-'a'][0]=1;
	ans[0]={s[0]-'a'};
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if((s[i]-'a') == j)
				dp[j][i]=dp[j][i-1]+1;
			else
				dp[j][i]=dp[j][i-1];
		}			
		int temp=dp[0][i];
		vector<int> v{0};
		for(int j=1;j<26;j++)
		{
			if(dp[j][i]==temp)
				v.push_back(j);
			else if(dp[j][i]>temp)
			{
				v.clear();
				v.push_back(j);
				temp=dp[j][i];
			}
		}
		ans[i]=v;
	}
	vector<int> res(26,0);
	for(int i=0;i<n;i++)
	{
		for(auto c:ans[i])
			res[c]++;
	}
	cout<<*max_element(res.begin(),res.end())<<endl;
	
	

	// cout<<*max_element(ans.begin(),ans.end())<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
