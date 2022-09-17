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

int fun(int n,int m,vector<int> c)
{
	int mx=0;
	vector<int> v(n,0);
	for(int i=0;i<m;i++)
		v[c[i]-1]=1;
	int i=0;
	while(i<n and v[i]!=1)
		i++;
	mx=i;
	int j=n-1;
	while(j>=0 and v[j]!=1)
		j--;
	mx=max(mx,n-1-j);
	while(i<j)
	{
		int temp=0;
		while(i<j and v[i]==0)
		{
			temp++;
			i++;
		}
		mx=max(mx,(temp+1)/2);
		i++;
	}
	return mx;
	
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	int n,m;
	cin>>n>>m;
	vector<int> c(m);
	for(int i=0;i<m;i++)
		cin>>c[i];
	int ans = fun(n,m,c);
	
	// cout<<"asni"<<endl;
	cout<<ans<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
