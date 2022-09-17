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

void update(int i, vector<int>& fen,int value)
{
	while(i<fen.size())
	{
		fen[i]+=value;
		i+=(i&(-i));
	}
}

int query(int i,vector<int>& fen)
{
	int ans=0;
	while(i>0)
	{
		ans+=fen[i];
		i-=(i&(-i));
	}
	return ans;
}

int find(int n,vector<int>& fen)
{
	int c=0;
	int p=0;
	for(int i=6;i>=0;i--)
	{
		if(fen[c+(1<<i)]+p<n)
		{
			c=c+(1<<i);
			p+=fen[c];
		}
	}
	return c+1;
}



int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();


	//multiset
	int n;
	cin>>n;
	vector<int> v(100,0);
	vector<int> fen(100,0);
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v[temp]++;
		update(temp,fen,1);
	}
	sort(all(v));
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	cout<<endl;	
	cout<<find(5,fen)<<endl;
	
	
	//count of inversion
	// int n;
	// cin>>n;
	// vector<int> v(n);
	// for(int i=0;i<n;i++)
	// {		
	// 	cin>>v[i];
	// }
	// int mx = *max_element(v.begin(),v.end());
	// vector<int> fen(mx+1,0);
	// int ans=0;
	// for(int i=n-1;i>=0;i--)
	// {
	// 	update(v[i],fen,1);
	// 	ans+=query(v[i]-1,fen);
	// }
	// cout<<ans<<endl;
	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}

// update
// i = i + (i&(-i))

//query
// i = i - (i&(-i))