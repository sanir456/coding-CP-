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
// ll w = 0;
// vector<pair<bool,ll>> tree;
// void build(vector<ll> v,int node,int l,int r)
// {
// 	// w++;
// 		if(l==r)
// 		{
// 			if(v[l]==0)
// 				tree[node]={true,v[l]};
// 			else
// 				tree[node]={false,v[l]};
// 		}	
// 		else
// 		{
// 			ll mid = l + (r-l)/2;
// 			build(v,2*node,l,mid);
// 			build(v,2*node+1,mid+1,r);
// 			if(tree[2*node].first == tree[2*node+1].first and tree[2*node].second==tree[2*node+1].second)
// 			{
// 				tree[node]={true,0};
// 			}
// 			else 			
// 			{
// 				if(tree[2*node].second>tree[2*node+1].second)
// 					tree[node]={false,26-tree[2*node].second+tree[2*node+1].second};
// 				else
// 					tree[node]={false,tree[2*node+1].second-tree[2*node].second};
// 			}
// 		}
// }


// ll getAnswer(ll node,ll l,ll r,ll s,ll e)
// {
// 	// cout<<s<<" "<<e<<endl;
// 	// w++;
// 	if(r<s or e<l)
// 		return 2;
// 	if(l<=s and e<=r)
// 	{
// 		if(tree[node].first)
// 			return 1;
// 		else 
// 			return 0;
// 	}
// 	ll mid = s+(e-s)/2;
// 	ll left = getAnswer(2*node,l,r,s,mid);
// 	ll right = getAnswer(2*node+1,l,r,mid+1,e);
// 	if(left==2)
// 		return right;
// 	else if(right==2)
// 		return left;
// 	else if(left==1 and right==1)
// 		return 1;
// 	else
// 		return 0;
// }

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
		string a;cin>>a;
		string b;cin>>b;
		vector<ll> v(n);
		vector<ll> v1(n);
		vector<ll> v2(n);
		for(ll i=0;i<n;i++)
		{
			if(a[i]<=b[i])
				v[i]=(ll)(b[i]-a[i]);
			else
				v[i]=(ll)('z'-a[i]+b[i]-'a'+1);
		}	
				
		v1[0] = 0; 
	    v2[0] = v[0]; 
	    for (ll i=1;i<n;i++)     
	    { 
	        if (i % 2)    v1[i] = v1[i-1] + v[i], v2[i] = v2[i-1]; 
	        else          v1[i] = v1[i-1], v2[i] = v2[i-1] + v[i]; 
	    } 
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			l--;
			r--;
	        ll s1, s2; 
	        s1 = v1[r], s2 = v2[r]; 
	        if (l > 0)      s1 -= v1[l-1], s2 -= v2[l-1]; 
	        if (abs(s1-s2) % 26 == 0)       cout << "YES" << '\n'; 
	        else                            cout << "NO" << '\n'; 
	     
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
