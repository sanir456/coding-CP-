#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TC(t) while(t--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define FOR(a,b,c) for(ll(a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll(a)=(b);(a)<=(c);++(a))
#define FORED(a,b,c) for(ll(a)=(b);(a)>=(c);--(a))
#define FOREACH(a,b) for(auto&(a):(b))

void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

class ds
{
public:
	priority_queue<int> mn;
	priority_queue<int> mx;
	vector<int> v;
	int k;

	void add_item(int n)
	{

		// if both heap have less than k element
		if(mn.size()<k && mx.size()<k)
		{
				mn.push(n);
				mx.push(-n);
		}	
		// is small k number heap is less than k element
		else if(mn.size()<k)
		{
			if((-1*mx.top())<n)
			{
				int temp = -1*mx.top();
				mn.push(temp);
				mx.pop();
				mx.push(-n);
			}
			else
				mn.push(n);
		}
		// if large k number heap is less than k elment
		else if(mx.size()<k)
		{
			if(mn.top()>n)
			{
				int temp = mn.top();
				mx.push(-temp);
				mn.pop();
				mn.push(n);
			}
			else
				mx.push(-n);
		}
		// if both heap have hreater than k element
		else if(mn.top()>n)
		{
			int temp = mn.top();
			if(temp < -1*mx.top())
				v.push_back(temp);
			mn.pop();
			mn.push(n);
		}
		else if((-1*mx.top())<n)
		{
			int temp = -1*mx.top();
			if(temp > mn.top())
				v.push_back(temp);
			mx.pop();
			mx.push(-n);
		}
		else
			v.push_back(n);


	}

	double avg()
	{
		
		if(v.size()==0)
			return 0;
		int sum = 0;
		for(int i:v)
		{
			sum+=i;
		}
		return (double)sum/v.size();
	}

};

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	

	ds obj;
	ll n,k;
	cin>>n>>k;
	obj.k=k;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		obj.add_item(temp);
	}
	cout<<obj.avg()<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
