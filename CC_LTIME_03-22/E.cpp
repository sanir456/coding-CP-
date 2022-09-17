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

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}


// https://www.geeksforgeeks.org/find-pair-maximum-gcd-array/
// ll findMaxGCD(vector<ll> v, ll l,ll r)
// {
//     ll high = 0;
//     for (ll i = l; i <=r; i++)
//         high = max(high, v[i]);
//  	ll divisors[high + 1] = { 0 };
 
//     for (ll i = l; i <= r; i++)
//     {
//         for (ll j = 1; j <= sqrt(v[i]); j++)
//         {
//             if (v[i] % j == 0)
//             {
//                 divisors[j]++;
//  	            if (j != v[i] / j)
//                     divisors[v[i] / j]++;
//             }
//         }
//     }
 
//     for (ll i = high; i >= 1; i--)
//         if (divisors[i] > 1)
//             return i;   
// }

// https://www.geeksforgeeks.org/find-pair-maximum-gcd-array/
int findMaxGCD(vector<ll> v, ll l,ll r)
{
    ll high = 0;
    for (ll i = l; i<=r; i++)
        high = max(high, v[i]);
 
    ll count[high + 1] = {0};
    for (ll i = l; i <=r; i++)
        count[v[i]]++;
 
    ll counter = 0;
 	for (ll i = high; i >= 1; i--)
    {
        ll j = i;
        counter = 0;
   		while (j <= high)
        {
            if(count[j] >=2)
               return j;
 
            else if (count[j] == 1)        
                counter++;        
 		    j += i;
 		    if (counter == 2)        
                return i;
        }
    }
}


ll maxGcd(vector<vector<ll>>& dp,ll l,ll r,vector<ll> v)
{
	if(l>=r)
		return -1;
	
	if(dp[l+1][r-1] > 0)
		dp[l][r] =  max(dp[l+1][r-1],gcd(v[l],v[r]));
	else
		dp[l][r] =  max({maxGcd(dp,l+1,r,v),maxGcd(dp,l+1,r-1,v),maxGcd(dp,l,r-1,v),gcd(v[l],v[r])});
	return dp[l][r];
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
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n+1);
		for(ll i=1;i<=n;i++)
			cin>>v[i];
		
		vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
		for(ll i=1;i<=n;i++)
		{
			for(ll j=j+1;j<=n;j++)
			{
				dp[i][j] = maxGcd(dp,i,j,v);	
			}
		}
		
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			// ll ans = findMaxGCD(v,l,r);
			cout<<dp[l][r]<<endl;
		}
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
