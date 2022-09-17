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
		ll n,m,k;
		cin>>n>>m>>k;
		string s1,s2;
		cin>>s1>>s2;
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		ll i=0,j=0;
		string ans="";
		ll a1=0,a2=0;
		while(i<n and j<m)
		{
			if(s1[i]<=s2[j] and a1<k)
			{
				ans.push_back(s1[i]);
				i++;
				a1++;
				a2=0;
			}
			else if(s2[j]<=s1[i] and a2<k)
			{
				ans.push_back(s2[j]);
				j++;
				a2++;
				a1=0;	
			}
			else if(a1<k)
			{
				ans.push_back(s1[i]);
				i++;
				a1++;
				a2=0;
			}
			else
			{
				ans.push_back(s2[j]);
				j++;
				a2++;
				a1=0;	
			}
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
