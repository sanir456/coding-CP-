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
	
	ll n,m;
	cin>>n>>m;
   	ll a[n];
   	for(int i=0;i<n;++i)
   	{
   		cin>>a[i];
	}
	order_set st;
	for(int i=0;i<m;++i)
	{
		st.insert(a[i]);
	}
	ll P=*st.find_by_order((m+1)/2-1);
	ll d=0;
	for(int i=0;i<m;++i)d+=abs(a[i]-P);
	cout<<d<<" ";
	for(int i=0;i<n-m;++i)
	{
		st.erase(st.find_by_order(st.order_of_key(a[i])));
		st.insert(a[i+m]);
		ll p=*st.find_by_order((m+1)/2-1);
		d+=abs(p-a[i+m])-abs(P-a[i]);
		if(!(m&1))d-=p-P;
		P=p;
		cout<<d<<" ";
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
