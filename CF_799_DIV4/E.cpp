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
	while(t--)
	{
		int n,s;
		cin>>n>>s;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<int> pre(n);
		pre[0]=v[0];
		for(int i=1;i<n;i++)
			pre[i]=pre[i-1]+v[i];
		
		vector<int> suff(n);
		suff[n-1]=v[n-1];
		for(int i=n-2;i>=0;i--)
			suff[i]=suff[i+1]+v[i];
		if(s>suff[0])
		{
			cout<<-1<<endl;
			continue;
		}
		if(s==suff[0])
		{
			cout<<0<<endl;
			continue;
		}
		reverse(suff.begin(),suff.end());
		int ans=lower_bound(all(suff),suff[n-1]-s)-suff.begin()+1;
		
		for(int i=0;i<n;i++)
		{
			if(suff[n-1]-pre[i]<s)
				break;
			int temp=lower_bound(all(suff),suff[n-1]-s-pre[i])-suff.begin();
			// cout<<i<<" "<<temp<<endl;
			if(temp==0 and v[n-1-temp]==0)
				temp--;
			ans=min(ans,i+1+temp+1);
		}
		cout<<ans<<endl;
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
