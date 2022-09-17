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
	
	string s1,s2;
	cin>>s1>>s2;
	int p;
	cin>>p;
	vector<int> v(26);
	for(auto c:s2)
		v[c-'a']++;
	
	int ans=0;
	for(int i=0;i<p;i++)
	{
		vector<int> v1(26);
		for(int j=0;j<s2.size();j++)
		{
			v1[s1[i+j*p]-'a']++;
		}	
		bool ok=true;
		for(int k=0;k<26 and ok;k++)
			if(v[k]!=v1[k])
				ok=false;
		if(ok)
			ans++;
		
		int l = i;
		int r = i+(s2.size()-1)*p;
		
		while(r+p<s1.size())
		{
			v1[s1[l]-'a']--;
			v1[s1[r+p]-'a']++;
			bool ok=true;
			for(int k=0;k<26 and ok;k++)
				if(v[k]!=v1[k])
					ok=false;
			if(ok)
				ans++;
			l=l+p;
			r=r+p;		
		}
	}	
	
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
