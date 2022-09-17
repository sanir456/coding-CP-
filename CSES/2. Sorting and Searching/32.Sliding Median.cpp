#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> order_set;


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
	
	ll n,k;
	cin>>n>>k;
	vector<int> v(n);
	order_set s;
	for(int i=0;i<k-1;i++)
	{
		cin>>v[i];
		s.insert(v[i]);
	}
	for(int i = k-1;i<n;i++)
	{
		cin>>v[i];
		s.insert(v[i]);
		int m = (k-1)/2;
		// int ans = s.find_by_order(m); 
		cout<<*s.find_by_order(m)<<" ";
		s.erase(s.upper_bound(v[i-k+1]));		
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
