// given a nXm grid you have to go from (1,1) to (n,m)
// return total number og good path such that total sum of element that lie in path is divisible by k

// n,m < 16
// gtid element, k < 10^18

//Approach(not final)
// df bfs on diagonal og grid, update map of map of every level traversal
// worst case i think 2^16


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

	return 0;
}
