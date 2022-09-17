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


int maxConsis(vector<int>& v,int mid)
{
	map<int,set<int>> freqNums; // numbers at each frequency
	map<int,int> numfreq; // frequencies for each number
	int res=1;
	for(int i=0;i<mid;i++)
	{
		int f = numfreq[v[i]];
		numfreq[v[i]]++;
		if(f==0)
		{
			freqNums[f+1].insert(v[i]);
		}
		else
		{
			freqNums[f+1].insert(v[i]);
			freqNums[f].erase(v[i]);	
		}
		res = max(res,f+1);
	} 
	int temp=res;
	for(int i=mid;i<v.size();i++)
	{
		int f = numfreq[v[i]];
		numfreq[v[i]]++;
		if(f==0)
		{
			freqNums[f+1].insert(v[i]);
		}
		else
		{
			freqNums[f+1].insert(v[i]);
			freqNums[f].erase(v[i]);	
		}
		temp = max(temp,f+1);
		
		f = numfreq[v[i-mid]];
		numfreq[v[i-mid]]--;
		if(f==temp and freqNums[f].size()==1)
		{
			temp = f-1;
		}
		freqNums[f-1].insert(v[i-mid]);
		freqNums[f].erase(v[i-mid]);
		res= max(temp,res);
	}
	return res;
}



int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	

	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int k;
	cin>>k;

	
	int ans=1;
	
	int l=1;
	int r=n;
	while(l<=r)
	{
		int mid = l+(r-l)/2;
		int res = maxConsis(v,mid);
		cout<<mid<<" "<<res<<endl;
		if(mid-res<=k)
		{
			ans=max(ans,res);
			l=mid+1;
		}
		else
			r=mid-1;
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
