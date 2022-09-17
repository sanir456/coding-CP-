#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

bool solve(int mid,int n,int m,int k)
{
	int rem = m-mid;
	int l=k-1;
	int r=n-k;
	int mn=0;
	int temp=mid-1;
	for(int i=l;i>0;i--)
	{
		mn+=temp;
		if(temp>1)
			temp--;
	}
	temp=mid-1;
	for(int i=r;i>0;i--)
	{
		mn+=temp;
		if(temp>1)
			temp--;
	}
	return rem>=mn;
}

int main(){
	init_code();
	
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	int l=1;
	int r=m;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(solve(mid,n,m,k))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
	
}

