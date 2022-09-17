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

bool comp(pair<ll,ll>& i,pair<ll,ll>& j)
{
	if(i.second<j.second)
		return true;
	return false;
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	ll n,k;
	cin>>n>>k;
	vector<pair<ll,ll>> v(n);
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v[i]={x,y};		
	}
	sort(all(v),comp);
	multiset<ll> e; ll c=0;
    for(ll i=0;i<n;i++){
        ll x = -v[i].first, y=-v[i].second;
        if (!e.size()) {e.insert(y);c++;}
        else{
            auto z = e.lower_bound(x);
            if (z==e.end()){
                if (e.size()<k) {e.insert(y); c++;}
            }
            else{
                e.erase(z);
                e.insert(y); c++;
            }
        }
    }
	cout<<c<<endl;


	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
