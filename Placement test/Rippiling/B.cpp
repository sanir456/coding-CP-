// we have n processer
// we have m job to do
// kth processer is most powerfull
// schedule m process such that kth processer get max job 
// every adjecent  processer job differance is atmost 1 
// each processer should have atleast 1 process

//constraint : m < 10^9

//solution: binary search on process
// T(n) = log(n)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int main(){
	init_code();
	
	// input
	int n,m,k;
	cin>>n>>m>>k;
	
	// solution
	int ans;
	int leftProcesser = k-1;
	int rightProcesser = n-k;
	int l=1;
	int r=m;
	while(l<=r)
	{
		int mid = l+(r-l)/2;
		int minimumLeftRemaingProcess = ((mid-1)*mid)/2 - ((mid-leftProcesser-1)*(mid-leftProcesser))/2;
		int minimumRightRemaingProcess = ((mid-1)*mid)/2 - ((mid-rightProcesser-1)*(mid-rightProcesser))/2;
		if(mid+minimumRightRemaingProcess+minimumLeftRemaingProcess<=m)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	
	//output
	cout<<ans;
	return 0;
}
