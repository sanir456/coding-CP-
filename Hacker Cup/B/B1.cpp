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

	init_code();
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int r,c;
		cin>>r>>c;
		vector<string> v(r);
		for(int i=0;i<r;i++)
			cin>>v[i];
		if(r==1 or c==1)
		{
			bool ok=true;
			for(int i=0;i<r and ok;i++)
				for(int j=0;j<c and ok;j++)
					if(v[i][j]=='^')
						ok=false;
			if(ok)
			{
				cout<<"Case #"<<T<<": Possible"<<endl;
				for(int i=0;i<r;i++)
					cout<<v[i]<<endl;
			
			}
			else
			cout<<"Case #"<<T<<": Impossible"<<endl;
			continue;
		}
		cout<<"Case #"<<T<<": Possible"<<endl;
			
		vector<string> ans(r,string(c,'^'));
		for(int i=0;i<r;i++)
			cout<<ans[i]<<endl;
		
		
	}	
	return 0;
}
