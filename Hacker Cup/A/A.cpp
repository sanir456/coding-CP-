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

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(101);
		
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			v[temp]++;
		}	
		if(n>2*k)
		{
			cout<<"Case #"<<T<<": NO"<<endl;
			continue;
		}
		bool ok=true;
		for(int i=1;i<=100;i++)
			if(v[i]>2)
			{
				ok=false;
				break;
			}
		if(ok)
			cout<<"Case #"<<T<<": YES"<<endl;
		else
			cout<<"Case #"<<T<<": NO"<<endl;
	}
	

	return 0;
}
