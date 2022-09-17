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


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}


bool isValid(vector<ll> v,ll mid)
{
	while(mid--)
	{

	}
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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(20,0);
		for(ll i=0;i<n;i++)
		{
			ll temp;
			cin>>temp;
			v[log2(temp)]++;
		}

		ll ans = 1, space_left = k;

        for (ll i = 0; i < n; i++) 
        {
            ll l = -1;

            for (ll j = 19; j >= 0; j--) 
            {
                if (v[j] and (1 << j) <= space_left) 
                {
                    l = j;
                    break;
                }
            }

            if (l == -1) 
            {
                space_left = k;
                ans++;
                for (ll j = 19; j >= 0; j--) 
                {
                    if (v[j] and (1 << j) <= space_left) 
                    {
                        l = j;
                        break;
                    }
                }
            }

            v[l] -= 1;
            space_left -= 1 << l;
        }

        cout << ans << endl;
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
