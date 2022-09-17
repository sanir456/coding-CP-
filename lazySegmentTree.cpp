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

// arrey , segement tree and lazy segment tree
int a[100005],tree[4*100005],lazy[4*10000]={0};

//bulid segment tree
void build(int idx,int l,int r)
{
	// if lead node
	if(l==r)
	{
		tree[idx]=a[l];
		return;
	}
	int mid = (l+r)/2;

	//build left node and right node
	build(idx*2+1,l,mid);
	build(idx*2+2,mid+1,r);
	
	//update current value of node baesd on left and righr node
	tree[idx]=tree[idx*2+1]+tree[idx*2+2];
	return;
}


//query on range
int query(int idx,int l,int r,int s,int e)
{
	
	//if update is remaining for current node then update node value
	//and pass update value to left and right node
	if(lazy[idx]!=0)
	{
		tree[idx]+=(lazy[idx]*(r-l+1));
		if(l!=r)
		{
			lazy[idx*2+1]+=lazy[idx];
			lazy[idx*2+2]+=lazy[idx];
		}
	}
	
	// range inside given range
	if(s<=l and e>=r)
	{
		return tree[idx];
	}
	
	//range outside given range
	if(s>r or e<l)
		return 0;

	// range overlap with given range
	int mid = (l+r)/2;
	int left=query(idx*2+1,l,mid,s,e);
	int right=query(idx*2+2,mid+1,r,s,e);
	return left+right;
}

//update node value on given range
void updateRange(int idx,int l,int r,int s,int e,int value)
{
	//if update is remaining for current node then update node value
	//and pass update value to left and right node
	if(lazy[idx]!=0)
	{
		tree[idx]+=(lazy[idx]*(r-l+1));
		if(l!=r)
		{
			lazy[idx*2+1]+=lazy[idx];
			lazy[idx*2+2]+=lazy[idx];
		}
	}
	
	// range inside given range	
	if(l>=s and e>=r)
	{
		tree[idx]+=(value)*(r-l+1);
		if(l!=r)
		{
			lazy[idx*2+1]+=value;
			lazy[idx*2+2]+=value;
		}	
		return;
	}
	
	//range outside given range
	if(s>r or l>e)
	{
		return;
	}
	
	//overlap range with given range
	int mid=(l+r)/2;
	updateRange(idx*2+1,l,mid,s,e,value);
	updateRange(idx*2+2,mid+1,r,s,e,value);
	tree[idx]=tree[idx*2+1]+tree[idx*2+2];
	return;
	
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
		int t;
		cin>>t;
		if(t==0)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(0,0,n-1,l,r)<<endl;
		}
		else
		{
			int l,r,value;
			cin>>l>>r>>value;
			updateRange(0,0,n-1,l,r,value);
		}
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


//input
// 5
// 1 1 1 1 1
// 3
// 0 2 3
// 1 2 3 3
// 0 2 3