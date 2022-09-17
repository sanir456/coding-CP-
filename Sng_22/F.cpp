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
	
	ll n;
	cin>>n;
	vector<ll> v1(n);
	for(ll i=0;i<n;i++)
		cin>>v1[i];
	vector<ll> v2(n);
	for(ll i=0;i<n;i++)
		cin>>v2[i];
	vector<pair<ll,ll>> ans;
	for(ll i=0;i<n;i++)
	{
		ll j=i;
		while(v2[j]!=v1[i])
			j++;
		for(ll k=j;k>i;k--)
		{
			swap(v2[k],v2[k-1]);
			ans.push_back({k,k+1});
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)
	{
		cout<<i.first<<" "<<i.second<<endl;
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
