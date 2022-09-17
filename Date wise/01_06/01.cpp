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


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

bool comp(pair<ll,vector<ll>> i,pair<ll,vector<ll>> j)
{
	if(i.first<j.first)
		return true;
	else if(i.first==j.first)
	{
		if(i.second.size()>j.second.size())
			return true;
	}
	return false;
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
		ll n;
		cin>>n;
		vector<pair<ll,vector<ll>>> q;
		for(ll i=0;i<n;i++)
		{
			ll c;
			cin>>c;
			ll mx = INT_MIN;
			vector<ll> cav(c);
			for(ll j=0;j<c;j++)
			{
				cin>>cav[j];
				mx = max(mx,cav[j]-j);
			}
			// cout<<mx<<endl;
			q.push_back({mx,cav});
		}	
		sort(q.begin(),q.end(),comp);
		ll l=0;
		ll r=INF;
		ll ans = INT_MAX;
		while(l<=r)
		{
			ll mid = l + (r-l)/2;
			ll p = mid;
			// cout<<"  "<<mid<<endl;
			bool ok = true;
			vector<pair<ll,vector<ll>>> temp=q;
			for(ll i=0;i<n and ok;i++)
			{
				// cout<<temp[i].first<<endl;
				vector<ll> cav=temp[i].second;
				for(ll i:cav)
				{
					// cout<<i<<" ";
					if(p>i)
						p++;
					else
					{
						ok = false;
						break;
					}
				}
				// cout<<endl;

			}
			if(ok)
			{
				// cout<<mid<<endl;
				ans = min(ans,mid);
				r = mid-1;
			}
			else
				l = mid+1;
		}
		cout<<ans<<endl;
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
	


	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
