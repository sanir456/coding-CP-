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
		int n;cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		if(n==1 and s1!=s2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(s1==s2)
		{
			cout<<"YES"<<endl;
			continue;
		}
		bool ok=true;
		for(int i=0;i<n and ok;i++)
		{
			
			if(s1[i]!=s2[i])
			{
				if(s2[i]=='a')
				{
					ok=false;
					break;
				}
				
				if(s2[i]=='b')
				{
					if(s1[i]=='c')
					{
						ok=false;
						break;
					}
					int temp=i+1;
					while(temp < n and s1[temp]!='b' and s1[temp]!='c')
						temp++;
					if(temp==n or s1[temp]=='c')
					{
						ok=false;
						break;
					}
					else
						swap(s1[temp],s1[i]);
				}
				else
				{
					if(s1[i]=='a')
					{
						ok=false;
						break;
					}
					else
					{
						
						int temp=i+1;
						while(temp < n and s1[temp]!='c' and s1[temp]!='a')
							temp++;
						if(temp==n or s1[temp]=='a')
						{
							ok=false;
							break;
						}
						else
							swap(s1[temp],s1[i]);		
					}
				}
				
				
			}	
		}
		if(ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
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
