#include<bits/stdc++.h>
using namespace std;


//funcation that take string and return of array which have integers with five numbers
vector<int> fun(string s)
{
	vector<int> ans;
	int n = s.size();
	for(int i=0;i<n;)
	{
		int temp = 0;
		for(int j=0;j<5 and i<n;j++,i++)
		{
			if(s[i]=='.')
				j--;
			else
				temp = temp*10 + (s[i]-'0');
		}
		ans.push_back(temp);

	}
	return ans;

}


int main(){
	
	//we use string to get individual number from double direct instead of calculating it
	string s;
	cin>>s;
	vector<int> ans = fun(s);

	
	//print arr of integer number
	for(auto i:ans)
		cout<<i<<" ";

	
	return 0;
}
