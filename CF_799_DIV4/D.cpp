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
		string s;
		cin>>s;
		int x;
		cin>>x;
		if(x==1)
		{
			cout<<16<<endl;
			continue;
		}
		if(x==1440)
		{
			if(s[0]==s[4] and s[1]==s[3])
				cout<<1<<endl;
			else
				cout<<0<<endl;
			continue;
			
		}
		int h=10*(s[0]-'0')+s[1]-'0';
		int m=10*(s[3]-'0')+s[4]-'0';
		set<pair<int,int>> mp;
		int ans=0;
		pair<int,int> p={h,m};
		while(mp.find(p)==mp.end())
		{
			if((h/10)==(m%10) and (h%10)==(m/10))
				ans++;
			mp.insert(p);
			m+=x;
			h+=(m/60);
			m%=60;
			h%=24;
			p={h,m};
			
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
