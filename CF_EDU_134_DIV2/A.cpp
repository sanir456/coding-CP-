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
	
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		vector<char> v{s1[0],s1[1],s2[0],s2[1]};
		sort(all(v));
		
		if(v[0]==v[1] and v[1]==v[2] and v[2]==v[3])
			cout<<0<<endl;
		else if(v[1]==v[2] and (v[0]==v[1] or v[2]==v[3]))
			cout<<1<<endl;
		else if(v[0]==v[1] and v[2]==v[3])
			cout<<1<<endl;
		else if(v[0]==v[1] or v[1]==v[2] or v[2]==v[3])
			cout<<2<<endl;
		else
			cout<<3<<endl;
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
