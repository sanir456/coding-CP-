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


ll lengthOfLIS(vector<ll>& nums) {
    ll n = nums.size();
    ll length = 1;
    vector<ll> v(n,0);
    v[0] = nums[0];
    for(ll i=1;i<n;i++)
    {
        if(nums[i]<v[0])
            v[0] = nums[i];
        else if(nums[i]>=v[length-1])
            v[length++] = nums[i];
        else
        {
            ll right = length-1;
            ll left = -1;
            while(right-left > 1)
            {
                ll m = left + (right-left)/2;
                if(v[m]>nums[i])
                    right = m;
                else 
                    left = m;
            }
            v[right] = nums[i];
        }
    }
    return length;
}


int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll> v1(n);
		for(ll i =0;i<n;i++)
			cin>>v1[i];
		vector<ll> v2(m);
		for(ll i =0;i<m;i++)
			cin>>v2[i];
		ll n1 = lengthOfLIS(v1);

		ll n2 = lengthOfLIS(v2);


		// cout<<n1<<" "<<n2<<endl;
		cout<<n1+n2<<endl;
		
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
