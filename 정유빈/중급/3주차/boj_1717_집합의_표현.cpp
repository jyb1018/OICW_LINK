#include <iostream>

using namespace std;

int parent[10000001];

int u_find(int t)
{

	if(parent[t] == t)
		return t;
	return parent[t] = u_find(parent[t]);

}

void _union(int p, int c)
{
	int a = u_find(c);
	int b = u_find(p);
	if(a<b)
		parent[b] = a;
	else if(a>b)
		parent[a] = b;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<=n; i++)
		parent[i] = i;
	for(int i = 0; i<m; i++)
	{
		int q, a, b;
		cin >> q >> a >> b;
		if(q == 0)
			_union(a,b);
		else if(u_find(a) == u_find(b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
