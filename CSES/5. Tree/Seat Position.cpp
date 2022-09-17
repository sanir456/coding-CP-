#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> order_set;


typedef long long ll;

#define endl '\n'

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int pos(order_set& s,int cp,int n)
{
	int l=1;
	int r=n;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		int order = s.order_of_key(mid);
		
		if(s.find(mid)!=s.end())
		{
			
		}
		
		else if(mid-order==cp)
			return mid;
		else if(mid-order>cp)
			r=mid-1;
		else
			l=mid+1;
	}
}

int main(){
	init_code();
	int n,m;
	cin>>n>>m;
	order_set s;
	vector<int> ans;
	while(m--)
	{
		int t,p;
		cin>>t>>p;
		if(s.empty() and t==2)
		{
			ans.push_back(p);
			continue;
		}
		int op=pos(s,p,n);
		if(t==1)
			s.insert(op);
		else
			ans.push_back(op);
	}
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}
