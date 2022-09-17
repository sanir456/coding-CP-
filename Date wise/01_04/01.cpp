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


int t,n,p;
long long a[200010],sum,x,y;
long long f(long long x)
{
	if(x>0)
	return x;
	return 0;
}

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{scanf("%lld",&a[i]);
	sum+=a[i];
	}
	sort(a+1,a+n+1);
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%lld%lld",&x,&y);
		p=lower_bound(a+2,a+n,x)-a;
		printf("%lld\n",min(f(x-a[p])+f(y+a[p]-sum),f(x-a[p-1])+f(y+a[p-1]-sum)));
	}

	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
