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

int bs(int a[],int l,int r,int x)
{
	if(r>=l){
		int mid = l + (r-l)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid] > x)
			return bs(a,l,mid+1,x);
		return bs(a,mid+1,r,x);
	}
	return -1;
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int a[] = {1};
	cout<<bs(a,0,0,-1);

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
