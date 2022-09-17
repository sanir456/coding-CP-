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

struct node 
{
	ll value;
	struct node* next;
};

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();

	
	ll n,k;
	cin>>n>>k;
	struct node* root;
	struct node* curr;
	cout<<n<<endl;
	ll temp;
	cin>>temp;
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->value = temp;
	t->next = NULL;
	root = t;
	curr = root;
	vector<ll>v(n);
	v[0]=temp;
	for(ll i=1;i<n;i++)
	{
		
		cin>>temp;
		v[i]=temp;
		struct node *t1 = (struct node*)malloc(sizeof(struct node));
	
		t1->value = temp;
		t1->next = NULL;
		curr->next = t1;
		curr = curr->next;
	}
	
	ll j =0;
		
	for(ll i=0;i<n;i++)
	{
		ll l = k*j;
		ll r = min(k*(j+1)-1,n-1);
		i=r;
		while(l<r)
			swap(v[l++],v[r--]);
		j++;
	}
	ll i = 0;
	curr = root;
	while(curr)
	{
		curr->value = v[i++];
		curr=curr->next;	
	}
	while(root)
	{
		cout<<root->value<<"->";
		root=root->next;
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



// 1-2-3-4-5
// p <- c n
// 	 p c n	