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

set<string> ans;

void fun(vector<char> v,vector<bool> used,string s)
{
	if(s.size()==v.size())
		ans.insert(s);
	for(ll i=0;i<v.size();i++)
	{
		if(!used[i])
		{
			used[i]=true;
			fun(v,used,s+v[i]);
			used[i]=false;
		}
	}
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	string s;
	cin>>s;
	vector<char> v;
	vector<bool> used(s.size(),false);
	for(auto c:s)
		v.push_back(c);
	fun(v,used,"");
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<endl;	
	
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
