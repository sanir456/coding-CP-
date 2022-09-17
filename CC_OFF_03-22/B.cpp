#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll z = 0;
        for(ll i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            if(temp==0)
                z++;
        }
        cout<<max(z,n-z)<<endl;
    }
	return 0;
}
