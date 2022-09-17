#include<bits/stdc++.h>
using namespace std;



void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int main(){

	init_code();
	double R1,R2;
	
	//Take input of resistor R1;
	cout<<"Enter resistors R1 valuse: ";
	cin>>R1;
	
	
	//Take input of resistor R2;
	cout<<"Enter resistors R2 valuse: ";
	cin>>R2;
	
	
	//Calculate resistor when R1 and R2 in series;
	double Rseries = R1+R2;
	
	//Calculate resistor when R1 and R2 in parallel;
	double Rparallel = (R1+R2)/(R1*R2);
	
	//Print resistor when R1 and R2 in series
	cout<<"Resistors connected in series : "<<Rseries<<endl;
	
	//Print resistor when R1 and R2 in parallel
	cout<<"Resistors connected in parallel : "<<Rparallel<<endl;

	//Calculate average of Rseries and Rparalll
	double avg= (Rseries+Rparallel)/2;
	
	//Print average of Rseries and Rparallel	
	cout<<"Average of Rseries and Rparallel : "<<avg<<endl;

	
	
	return 0;
}
