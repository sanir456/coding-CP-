// give n node and n-1 eddge such that it form a tree
// edge hase some weight show reliability b/w two node
// minimize maitainance such that every node hase atmost k reliable node

#include<bits/stdc++.h>
using namespace std;



void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}


// int findEarliestMonth(vector<int> stockPrice)
// {
// 	int n=a.size();
// 	vector<int> pre(n,0);
// 	pre[0]=a[0];
// 	for(int i=1;i<n;i++)
// 		pre[i]=pre[i-1]+a[i];
// 	int ans=INT_MAX;
// 	int idx=0;
// 	for(int i=0;i<n-1;i++)
// 	{
// 		int avg1=pre[i]/(i+1);
// 		int avg2=(pre[n-1]-pre[i])/(n-i-1);
// 		if(ans>abs(avg1-avg2))
// 		{
// 			ans=abs(avg1-avg2);
// 			idx=i+1;
// 		}
// 	}
// 	return idx;
// }

string getEncryptedNumber(vector<int> numbers)
{
	while(numbers.size()!=2)
	{
		vector<int> temp;
		for(int i=0;i<numbers.size()-1;i++)
		{
			temp.push_back((numbers[i]+numbers[i+1])%10);
		}
		numbers=temp;
	}
	return  to_string(numbers[0])+to_string(numbers[1]);
}

int main(){
	init_code();
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<getEncryptedNumber(v);
		

	

	return 0;
}
