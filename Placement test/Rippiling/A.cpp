// for every index get kth lagest element from right side if not possible print -1 for that index
// index is 1-based
// n < 10^6


// Solution: order set
// T(n): O(nlog(n))

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int main(){
	
	
	//input
	init_code();
	int n,k;
	cin>>n>>k;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
		cin>>v[i];
		
	//solution
	order_set s;
	map<int,int> m;
	vector<int> ans(n+1,-1);
	for(int i=n;i>0;i--)
	{
		m[v[i]]=i;
		s.insert(v[i]);
		int orderOfIth = s.order_of_key(v[i]); 
		if(orderOfIth + k < s.size())
		{
			ans[i]=m[*s.find_by_order(orderOfIth + k)];
		}
	}	
	ans.erase(ans.begin()+0);
	
	//output
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
