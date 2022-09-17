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

int a[100005],tree[4*100005];
void build(int idx,int l, int r)
{
	if(l==r)
	{
		tree[idx]=a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*idx+1,l,mid);
	build(2*idx+2,mid+1,r);
	tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
	return;
}

int query(int idx,int l,int r,int s,int e)
{
	if(l>=s and e>=r)
		return tree[idx];
	if(e<l or s>r)
		return INT_MIN;
	int mid=(l+r)/2;
	int left = query(2*idx+1,l,mid,s,e);
	int right = query(2*idx+2,mid+1,r,s,e);
	return max(left,right);
}

void pointUpdate(int idx,int l,int r,int node,int val)
{
	if(l==r)
		tree[idx]=val;
	else
	{
		int mid = (l+r)/2;
		if(node<=mid)
			pointUpdate(idx*2+1,l,mid,node,val);
		else
			pointUpdate(idx*2+2,mid+1,r,node,val);
		tree[idx]=max(tree[idx*2+1],tree[idx*2+2]);
	}
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	build(0,0,n-1);
	int q;
	cin>>q;
	while(q--)
	{
		int t,l,r;
		cin>>t;
		cin>>l>>r;
		if(t==1)
			cout<<query(0,0,n-1,l,r)<<endl;
		else
			pointUpdate(0,0,n-1,l,r);
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


//input with update query
// 10
// 9 4 4 2 5 7 4 6 3 6
// 3
// 1 1 9
// 0 3 10
// 1 1 9