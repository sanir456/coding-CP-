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

const ll N=1e5+5;
vector<vector<ll>> factors(N);
bool prime[N];

void primesFactor(){
    memset(prime, true, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(ll i=2; i<N; i++){
        if(prime[i]){
            for(ll j = 2*i; j<N; j+=i){
                factors[j].pb(i);
                prime[j] = false;
            }
        }
    }
}

int dp[1000][20][2];

int count(int sum,int idx,bool bound,string r)
{
	if(idx<0)
		return prime[sum];
	if(dp[sum][idx][bound]!=-1)
		return dp[sum][idx][bound];
	int end=(bound)?(r[idx]-'0'):9;
	// cout<<sum<<" "<<idx<<" "<<end<<" "<<r<<endl;
	int ans=0;
	for(int i=0;i<=end;i++)
	{
		ans+=count(sum+i,idx-1,(bound and (i==end)),r);
	}
	dp[sum][idx][bound]=ans;
	return ans;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	primesFactor();
	int l,r;
	cin>>l>>r;
	memset(dp,-1,sizeof(dp));
	string sr = to_string(r);
	reverse(all(sr));
	int right = count(0,sr.size()-1,1,sr);
	cout<<right<<" "<<sr<<endl;
	
	string sl = to_string(l-1);
	reverse(all(sl));
	memset(dp,-1,sizeof(dp));
	int left = count(0,sl.size()-1,1,sl);
	cout<<left<<" "<<sl<<endl;
	cout<<right-left<<endl;
	
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
