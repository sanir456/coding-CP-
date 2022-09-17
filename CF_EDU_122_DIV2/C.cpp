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

bool isValid1(ll mid,ll ch,ll cd,ll mh,ll md,ll k,ll w,ll a)
{
	ll ncd = cd+mid*w;
	ll nch = ch+(k-mid)*a;
	// cout<<cd<<" "<<ch<<endl;
	if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
		return true;
	
	ncd = cd + (k-mid)*w;
	nch = ch + mid*a;
	if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
		return true;
	return false;
}

bool isValid(ll mid,ll ch,ll cd,ll mh,ll md,ll k,ll w,ll a)
{
	ll ncd = cd+mid*w;
	ll nch = ch+(k-mid)*a;
	// cout<<cd<<" "<<ch<<endl;
	if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
		return true;
	
	ncd = cd + (k-mid)*w;
	nch = ch + mid*a;
	if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
		return true;
	return false;
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
		ll ch,cd,mh,md,k,w,a;
		cin>>ch>>cd>>mh>>md>>k>>w>>a;
		ll l=0;
		ll r=k;
		bool ok=false;
		if((mh+cd-1)/cd<((ch+md-1)/md+1))
			ok = true;
	
		for(ll i=0;i<=k;i++)
		{
			ll ncd = cd+i*w;
			ll nch = ch+(k-i)*a;
			// cout<<cd<<" "<<ch<<endl;
			if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
			{
				ok = true;
				break;
			}
			
			ncd = cd + (k-i)*w;
			nch = ch + i*a;
			if((mh+ncd-1)/ncd<((nch+md-1)/md+1))
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


	
	time(&end);
    double time_taken = double(end - start);
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  	#endif
	return 0;
}
