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
	
	ll q,k;
	cin>>q>>k;
	vector<ll> n;
	vector<ll> p;
	for(ll i=0;i<q;i++)
	{
		ll temp;
		cin>>temp;
		if(temp<0)
			n.push_back(temp);
		else
			p.push_back(temp);
	}
	sort(n.begin(),n.end());
	sort(p.begin(),p.end());
	
	ll ans = 0;
	if(k>=n.size())
	{
		for(auto i:n)
			ans+=abs(i);
		k = k-n.size();
		
		if(k%2==0)
		{
			for(ll i:p)
				ans+=i;	
		}
		else
		{
			
			if(n.size()!=0 and (p.size()==0 or p[0]>abs(n[n.size()-1])))
				ans-=2*abs(n[n.size()-1]);
			else
				ans-=2*p[0];
			for(ll i:p)
				ans+=i;
		}
		
	}
	else
	{
		ll i=0;
		for(i=0;i<n.size() and k>0;i++,k--)
		{
			ans+=abs(n[i]);
			// cout<<ans<<endl;
		}
		for(i;i<n.size();i++)
			ans+=n[i];
		for(ll i=0;i<p.size();i++)
			ans+=p[i];
	}
	cout<<ans<<endl;
		

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
	
