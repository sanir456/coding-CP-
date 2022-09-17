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


int fun1(int n,int k)
{
	if(n==0) return 0;
	else if(n%2) return fun1(n/2,2*k)+k;
	else return fun1(n/2,2*k)-k;
}
int fun()
{
	int res=fun1(20,1);
	cout<<res<<endl; 
}



int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int n=1221;
	int sum=0;
	int t=n;
	while(n)
	{
		int r=n%10;
		n=n/10;
		sum=sum*10+r;
	}
	
	if(t==sum) 
		cout<<"m1"<<endl;
	else
		cout<<"m2"<<endl;



	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
