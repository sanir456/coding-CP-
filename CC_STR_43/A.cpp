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
		int n,x;
		cin>>n>>x;
		int temp=x;
		if(x>(n+1)/2)
		{
			cout<<-1<<endl;
			continue;
		}
		string s;
		for(int i=0;i<n/2;i++)
		{
			if(x!=0)
			{
				s+=('a'+i);
				x--;
			}
			else
				s+='a';
		}
		string s1=s;\
		
		reverse(all(s1));
		if(n%2==1)
		{
			if(temp==(n+1)/2)
				s1=s+'z'+s1;
			else			
				s1=s+'a'+s1;	
		}
		else
			s1=s+s1;
		cout<<s1<<endl;
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
