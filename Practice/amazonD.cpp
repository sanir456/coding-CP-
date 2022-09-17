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

struct SinglyLinkedListNode {
	int data;
	struct SinglyLinkedListNode* next;
};

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
					
	
	int n;
	cin>>n;
	struct SinglyLinkedListNode* dummy = new SinglyLinkedListNode();
	dummy->data = 0;
	dummy->next = nullptr;
	struct SinglyLinkedListNode* temp = dummy;

	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		struct SinglyLinkedListNode* node = new SinglyLinkedListNode();
		node->data = t;
		node->next = nullptr;
		temp->next = node;
		temp=temp->next;	
	}
	
	struct SinglyLinkedListNode* head = dummy->next;

	vector<int> dp(n);
	dp[0]=1;
	temp=head->next;
	struct SinglyLinkedListNode*prev = head;
	int i=1;
	while(temp!=nullptr)
	{
		if(prev->data >= temp->data)
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
		prev = temp;
		temp = temp->next;
		i++;
	}
	
	int mx = *max_element(dp.begin(),dp.end());
	int idx = -1;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==mx)
		{
			idx=i;
			break;
		}
	}
	
	idx = dp[i]-idx;
	for(int i=0;i<=idx;i++)
	{
		head=head->next;
	} 	
	
	for(int i=0;i<mx;i++)
	{
		cout<<head->data<<endl;
		head=head->next;
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
