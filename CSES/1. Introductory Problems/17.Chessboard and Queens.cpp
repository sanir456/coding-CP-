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

vector<string> input(8);
vector<vector<bool>> b(8,vector<bool>(8,false));
	

bool place(int x, int y){
    bool yes = true;
    for(int i = 0; i < 8; i++)
        if(b[x][i] || b[i][y])
            yes = false;
    for(int i = 0; x-i >= 0 && y-i >= 0; i++)
        if(b[x-i][y-i])
            yes = false;
    for(int i = 0; x-i >= 0 && y+i < 8; i++)
        if(b[x-i][y+i])
            yes = false;
    return yes;
}

bool check(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(b[i][j] && input[i][j]=='*')
                return false;
    return true;
}

ll ans = 0;
void fun(ll i)
{ 
	if(i == 8){
        if(check())
            ans++;
        return;
    }
    for(int j = 0; j < 8; j++){
        if(place(i, j)){
            b[i][j] = true;
            fun(i+1);
            b[i][j] = false;
        }
    }
}

int main(){
	time_t start, end;
	time(&start);
	FAST_IO
	init_code();
	
	for(ll i=0;i<8;i++)
		cin>>input[i];
	fun(0);
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
