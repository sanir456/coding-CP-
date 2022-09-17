#include<iostream>
#include<vector>
using namespace std;

int main(){
	int i;
	vector<int> inputVector;
	int value;
	
	cin>>value;
	while(value!=-1)
	{
		inputVector.push_back(value);
		cin>>value;
	}
	
	int lastElement = inputVector.back();
	
	for(auto element : inputVector)
	{
		if(element==lastElement)
		{
			cout<<"IGNORE"<<endl;
		}
		else
		{
			cout<<element<<endl;
		}
	}
}