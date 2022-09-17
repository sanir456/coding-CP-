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

ll isValid(vector<ll>& v,ll diff)
{
	ll pair = 0;
	ll i=1,j=0;
	while(i<v.size())
	{
		while(v[i]-v[j]>diff)
			j++;
		pair+=(i-j);
		i++;
	}
	return pair;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	sort(all(v));
	
	ll l=0;
	ll r=v[n-1]-v[0];
	ll diff;
	while(l<=r)
	{
		ll mid = l + (r-l)/2;
		if(isValid(v,mid)>=k)
		{
			diff = mid;
			r=mid-1;
		}
		else
			l =mid+1;
	}	
	vector<ll> ans;
	ll i=1,j=0;
	while(i<n)
	{
		while(v[i]-v[j]>=diff)
			j++;
		for(ll k=j;k<i;k++)
			ans.push_back(v[i]-v[k]);
		i++;
	}
	for(ll i=ans.size();i<k;i++)
		ans.push_back(diff);
	sort(all(ans));
	
	for(auto i:ans)
		cout<<i<<" ";
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
