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
 
vector<ll> q;
	

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


ll get_first_bit(ll n){
	return 63 - __builtin_clzll(n);
}

ll get_bit_count(ll n){
	return __builtin_popcountll(n);
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	vector<ll> fact;
	ll f = 6;
	ll d = 4;
	while(f<=power(10,12))
	{
		fact.push_back(f);
		f*=d;
		d++;
		
	}
	
	vector<pair<ll,ll>> fact_sum(1 << fact.size());
		fact_sum[0] = {0, 0};
		for(ll i = 1; i < (1 << fact.size()); i++){
			auto first_bit = get_first_bit(i);
			fact_sum[i].first = fact_sum[i ^ (1 << first_bit)].first + fact[first_bit];
			fact_sum[i].second = get_bit_count(i);
		}
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll res = get_bit_count(n);
		for(auto i : fact_sum){
			if(i.first <= n){
				res = min(res, i.second + get_bit_count(n - i.first));
			}
		}
		cout << res << "\n";
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
		