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
        if(n==1)
        {
            cout<<n<<endl;
            continue;
        }
        for(ll i=0;i<n/2;i++)
            cout<<i*2+1<<" "<<2*(i*2+1)<<" ";
        if(n%2==1)
            cout<<n;
        cout<<endl;
        
    }
	return 0;
}
