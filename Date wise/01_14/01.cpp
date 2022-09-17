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
		string S,T;
		cin>>S>>T;
		vector<ll> v(26,0);
		for(char a:S)
			v[a-'a']++;
		if(v[0]==0 or v[1]==0 or v[2]==0)
		{
			for(ll i=0;i<26;i++)
			{
				while(v[i]>0)
				{
					cout<<(char)('a'+i);
					v[i]--;
				}	
			}
			cout<<endl;
		}
		else
		{
			if(T[0]=='a')
			{
				if(T[1]=='b')
				{
					while(v[0]>0)
					{
						cout<<'a';
						v[0]--;
					}
					while(v[2]>0)
					{
						cout<<'c';
						v[2]--;
					}
				}
				else
				{
					while(v[0]>0)
					{
						cout<<'a';
						v[0]--;
					}
					while(v[1]>0)
					{
						cout<<'b';
						v[1]--;
					}
						
				}
			}
			for(ll i=0;i<26;i++)
			{
				while(v[i]>0)
				{
					cout<<(char)('a'+i);
					v[i]--;
				}	
			}
			cout<<endl;
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
