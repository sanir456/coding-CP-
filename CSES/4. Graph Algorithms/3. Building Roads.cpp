#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);

#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int find(vector<int>& root,int x)
{
	if(x==root[x])
		return x;
	return root[x]=find(root,root[x]);
}


void unionFind(set<int>& s,vector<int>& root,vector<int>& rank,int x,int y)
{
	int rootX=find(root,x);
	int rootY=find(root,y);
	if(rootX!=rootY)
	{
		if(rank[rootX]>rank[rootY])
			swap(rootY,rootX);
		root[rootY]=rootX;
		rank[rootX]+=rank[rootY];
		s.erase(rootY);
	}
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int n,m;
	cin>>n>>m;
	
	vector<int> root(n+1);
	vector<int> rank(n+1,1);
	set<int> s;	

	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		s.insert(i);
	}
	
	while(m--)
	{
		int i,j;
		cin>>i>>j;
		unionFind(s,root,rank,i,j);
	}
	auto it=s.begin();
	cout<<s.size()-1<<endl;
	int a=*it;
	it++;
	while(it!=s.end())
	{
		cout<<a<<" "<<*it<<endl;
		it++;
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
