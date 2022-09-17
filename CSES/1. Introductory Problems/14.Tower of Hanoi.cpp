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

void fun(int from,int to,int n)
{
	if(n == 1)
	{
		cout<<from<<" "<<to<<endl;
		return;
	}
	int help = 6-from-to;
	fun(from,help,n-1);
	cout<<from<<" "<<to<<endl;
	fun(help,to,n-1);
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll n;
	cin>>n;
	cout<<(1<<n)-1<<endl;
	fun(1,3,n);

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
