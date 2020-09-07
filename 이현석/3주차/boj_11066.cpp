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
const int INF = 2e9;
//const ll INF = 2e15;
const int ALP=26;
const int SZ=1<<17;


ll N, arr[505], dp[505][505],psum[505];

void solve(){
	cin>>N;
	rep(i,1,N+1)cin>>arr[i];
	rep(i,1,N+1)psum[i]=psum[i-1]+arr[i];
	rep(i,1,N+1)rep(j,1,N+1)dp[i][j]=INF;
	rep(i,1,N+1)dp[i][i]=0;
	for(int d=1;d<N;++d){
		for(int i=1;i<N+1-d;++i){
			for(int j=i;j<i+d;++j){
				dp[i][i+d]=min(dp[i][i+d], dp[i][j]+dp[j+1][i+d]+psum[i+d]-psum[i-1]);
			}
		}
	}
	cout<<dp[1][N]<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	for(int i=1;i<=tc;++i)
		solve();
	
	
	return 0;
}
