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
	
	ll n;
	cin>>n;
	map<stack<char>,ll> m1;
	map<stack<char>,stack<char>> m2;
	ll ans = 0;
	ll c = 0;
	while(n--)
	{
		string s;
		cin>>s;
		stack<char> st;
		stack<char> stt;
		for(ll i=0;i<s.size();i++)
		{
			if(st.empty())
			{
				st.push(s[i]);
				if(s[i]==')')
					stt.push('(');
				else
					stt.push(')');
			}
			else
			{
				if(s[i]==')' and st.top()=='(')
				{	
					st.pop();
					stt.pop();
				}
				else 
				{
					st.push(s[i]); 
					if(s[i]==')')
						stt.push('(');
					else
						stt.push(')');
				}
			}
		}
		if(!st.empty())
		{
			m1[st]++;
			m2[st]=stt;
		}
		else
			c++;
	}

	// for(auto i : m1)
	// {
	// 	stack<char> temp = i.first;
	// 	while(!temp.empty())
	// 	{
	// 		cout<<temp.top()<<" ";
	// 		temp.pop();
	// 	}
	// 	cout<<i.second<<endl;
		
	// }

	// cout<<endl;

	ans = c/2;
	for(auto i : m1)
	{
		if(i.second > 0)
		{
			ans += min(i.second,m1[m2[i.first]]);
			m1[i.first]=0;
			m1[m2[i.first]]=0;
		}
		// stack<char> temp = i.first;
		// while(!temp.empty())
		// {
		// 	cout<<temp.top()<<" ";
		// 	temp.pop();
		// }
		// cout<<i.second<<endl;
		// cout<<ans<<endl;
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
