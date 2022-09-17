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

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll rx,ry;
		cin>>rx>>ry;
		ll dx,dy;
		cin>>dx>>dy;
		if(dx==rx || dy==ry)
		{	
			cout<<0<<endl;
			continue;
		}

		if(dx>rx && dy>ry)
		{
			// cout<<1<<" ";
			cout<<min(abs(rx-dx),abs(ry-dy))<<endl;
		}
		else if(dx>rx && dy<ry)
		{
			// cout<<2<<" ";
			cout<<min(abs(rx-dx),m-ry + m-dy)<<endl;
		}
		else if(dx<rx && dy>ry)
		{
			// cout<<3<<" ";
			cout<<min(abs(dy-ry),n-rx+n-dx)<<endl;
		}
		else
		{
			// cout<<4<<" ";
			cout<<min(m-ry+m-dy,n-rx+n-dx)<<endl;
		}
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
