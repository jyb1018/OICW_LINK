#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int MOD = 1e9+7;
const int MAX = 10101;

struct Edge{
	ll a, b, w;
	Edge(): Edge(-1,-1,0){}
	Edge(ll a1, ll b1, ll w1): a(a1), b(b1), w(w1){}
	//bool operator <(const Edge& O)const{return w < O.w;}
};
struct compare{
	bool operator()(Edge &e1, Edge &e2){
		return e1.w > e2.w;
	}
};

int v, e, uf[MAX];
//vector<ll> adj[MAX];
//Edge eg[MAX];

int find(int a){
	if(uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v>>e;
	priority_queue<Edge, vector<Edge>, compare> qu;
	fill(uf, uf+v+1, -1);
	for (int i=0;i<e;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		qu.push(Edge(a,b,w));
	}
	ll ans = 0;
	while(qu.size()){
		Edge now = qu.top();
		qu.pop();
		ll a,b;
		a = now.a; b = now.b;
		if(!merge(a, b))continue;
		ans += now.w;
	}
	
	cout << ans << '\n';
	
	return 0;
}
