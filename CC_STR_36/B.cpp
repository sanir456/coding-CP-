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
	if(i.first>j.first)
		return true;
	else if(i.first==j.first)
		if (i.second>j.second)
			return true;
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
		vector<ll> odd;
		vector<ll> even;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			if(temp&1)
				odd.push_back(temp);
			else
				even.push_back(temp);
		}
		sort(all(odd));
		sort(all(even));
		
		reverse(all(odd));
		reverse(all(even));
		vector<pair<ll,ll>> ans1(3);
		ll ans = INT_MIN;
		
		//oo
		ll abs1;
		ll a = 0;
		ll b = 0;
		ll i=0,j=0;
		bool take =true;
		while(true)
		{
			if(take)
			{
				if(i<odd.size())
				{
					a+=odd[i++];
					if(i<odd.size())
						b+=odd[i++];
					else
					{
						if(j<even.size())
							a+=even[j++];
						break;
					}
				}
				else
					break;
			}
			else
			{
				if(j<even.size())
				{
					a+=even[j++];
					if(j<even.size())
						b+=even[j++];
					else
					{
						if(i<odd.size())
							a+=odd[i++];
						break;
					}
				}
				else
					break;
			}
			take=!take;
		}
		
		// cout<<a<<" "<<b<<endl;
		ans1[0]={max(a,b),min(a,b)};
		// cout<<ans<<endl;
		
		
		//ee
		a = 0;
		b = 0;
		i=0,j=0;
		take =false;
		while(true)
		{
			if(take)
			{
				if(i<odd.size())
				{
					a+=odd[i++];
					if(i<odd.size())
						b+=odd[i++];
					else
					{
						a+=even[j++];
						break;
					}
				}
				else
					break;
			}
			else
			{
				if(j<even.size())
				{
					a+=even[j++];
					if(j<even.size())
						b+=even[j++];
					else
					{
						a+=odd[i++];
						break;
					}
				}
				else
					break;
			}
			take=!take;
		}
		
	
	
		// cout<<a<<" "<<b<<endl;	
		ans1[1]={max(a,b),min(a,b)};
		
		// cout<<ans<<endl;
		//oe
		ll abs3;
		a = 0;
		b = 0;
		i=0,j=0;
		take =true;
		while(true)
		{
			if(take)
			{
				if(i<odd.size())
					a+=odd[i++];
				else
				{
					if(j<even.size())
						b+=even[j++];
					break;
				}
				if(j<even.size())
					b+=even[j++];
				else
					break;
			}
			else
			{
				if(j<even.size())
					a+=even[j++];
				else
				{
					if(i<odd.size())
						b+=odd[i++];
					break;
				}
				if(i<odd.size())
					b+=odd[i++];
				else
					break;
			}
			take=!take;
		}
		
		
		
		// cout<<a<<" "<<b<<endl;
		ans1[2]={max(a,b),min(a,b)};
		
		// sort(all(ans1),comp);
		
		// for(auto i:ans1)
		// 	cout<<i.first<<" "<<i.second<<endl;
		
		pair<ll,ll> p1;
		if(ans1[0].first+ans1[0].second>=ans1[1].first+ans1[1].second)
			p1=ans1[0];
		else
			p1=ans1[1];
		pair<ll,ll> p2=ans1[2];
		
		ll z;
		if(p1.first+p1.second>p2.first+p2.second)
			z = p1.first;
		else if(p1.first+p1.second==p2.first+p2.second)
		{
			if(abs(p1.first-p1.second)<=abs(p2.first-p2.second))
				z = p1.first;
			else
				z = p2.first;
		}
		else
			z=p2.first;
		cout<<z<<endl;
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
