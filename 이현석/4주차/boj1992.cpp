#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(v) v.begin(), v.end()
// #define int long long
/*
	continue break front push size empty begin insert unsigned lower_bound upper_bound resize emplace_back priority_queue
*/
using namespace std;


using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ti = tuple<int, int, int, int>;

//const int MOD = 1e9+7;
const int MAX = 500050;
const int INF = 2e9;
//const ll INF = 2e15;
const int ALP=26;
const int SZ=1<<18;

int N,a[101][101];


void func(int R,int C,int n){
	bool isend=1;
	int flag = a[R][C];
	for(int i=R;i<R+n;++i){
		for(int j=C;j<C+n;++j){
			if(flag!=a[i][j])isend=0;
		}
	}
	if(isend){
		cout<<flag;
		return;
	}
	cout<<"(";
	func(R,C,n/2);
	func(R,C+n/2,n/2);
	func(R+n/2,C,n/2);
	func(R+n/2,C+n/2,n/2);
	cout<<")";
}

void solve(){
	cin>>N;
	rep(i,0,N){
		string s;cin>>s;
		for(int j=0;j<N;++j){
			a[i][j]=s[j]-'0';
		}
	}
	func(0,0,N);
	cout<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	// int tc;cin>>tc;
	// for(int i=1;i<=tc;++i)
		solve();
	
	return 0;
}
