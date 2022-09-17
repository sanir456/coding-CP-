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

ll fun(vector<ll>& dp,bool oc,char c,ll i,string s)
{
	// cout<<i<<" "<<oc<<" "<<c<<endl;
	if(i==s.size()-1 and !oc)
		return 1;
	else if(i>=s.size())
	{
		if(oc)
			return 1;
		else
			return 0;
	}
	
	if(dp[i]!=INF and !oc)
		return dp[i];
	
	if(oc)
	{
		if(c==s[i])
			dp[i]=min(dp[i],fun(dp,false,' ',i+1,s));
		else
			dp[i]=1+min(fun(dp,false,' ',i,s),fun(dp,true,c,i+1,s));	
	}
	else
	{
		if(s[i]==s[i+1])
		{
			dp[i]=min(fun(dp,false,' ',i+2,s),dp[i]);
			dp[i+1]=min(fun(dp,false,' ',i+2,s),dp[i+1]);
		}
		else
			dp[i]=dp[i+1]=1 + min(fun(dp,true,s[i+1],i+2,s),fun(dp,true,s[i],i+2,s));
	}
	return dp[i];
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
		string s;
    cin >> s;
    int m = 0, n = (int)s.size();
    vector<bool>prev(26, false);
    for(auto &i : s){
        if(prev[i - 'a']){
            m += 2;
            for(int j = 0; j < 26; j++) prev[j] = false;
        }
        else prev[i - 'a'] = true;
    }
 
    cout << n - m << endl;
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
