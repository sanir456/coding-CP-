#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
     ll x;
     cin>>x;
     vector<ll> v(3);
     cin>>v[0]>>v[1]>>v[2];
     sort(v.begin(),v.end());
     cout<<(x-1)*v[0]+v[1]<<endl;
    }
	return 0;
}
