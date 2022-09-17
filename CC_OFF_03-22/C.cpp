#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        bool ok = false;
        for(ll i=1;i<=min(n,x);i++)
        {
            if(x%i==0 and n+1-i>=(x/i))
            {
                ok = true;
                break;
            }
            
        }
        
        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
	return 0;
}
