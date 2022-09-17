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

void showdq(deque<ll> g)
{
    deque<ll>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it<<endl;

}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	string s;
	cin>>s;
	deque<ll> q;
	bool ok= true;
	ll n = s.size();
	if(s[n-1]=='l')
		ok = false;
	q.push_back(n);	
	for(ll i = n-2;i>=0;i--)
	{
		if(s[i]!=s[i+1])
			ok = !ok;
		if(ok)
			q.push_front(i+1);
		else
			q.push_back(i+1);
		// showdq(q);
		// cout<<endl;
	}
	showdq(q);

	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
