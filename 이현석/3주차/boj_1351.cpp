#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(v) v.begin(), v.end()

/*
	continue break front push size empty begin insert unsigned lower_bound upper_bound resize emplace_back priority_queue
*/
using namespace std;


using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

//const int MOD = 1e9+7;
const int MAX = 500050;
//const int INF = 2e9;
const ll INF = 2e15;
const int ALP=26;
const int SZ=1<<17;

map<ll,ll>dp;
ll N,P,Q;

ll topdown(ll i){
	if(dp.count(i))return dp[i];
	return dp[i]=topdown(i/P)+topdown(i/Q);
}

void solve(){
	cin>>N>>P>>Q;
	dp[0]=1;
	cout<<topdown(N)<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	// int tc;cin>>tc;
	// for(int i=1;i<=tc;++i)
		solve();
	
	
	return 0;
}
