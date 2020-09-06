#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000

using namespace std;



struct edge {
	int v1;
	int v2;
	int weight;
	edge(int v1, int v2, int w) : v1(v1), v2(v2), weight(w) {}
	edge() : edge(0,0,0) {}
};

bool edge_operator(edge a, edge b)
{
	return a.weight < b.weight;
}

int V, E;
int V_selected;
int parent[10001];


int union_find(int index)
{
	if(parent[index] == 0 || parent[index] == index)
		return parent[index] = index;
	return parent[index] = union_find(parent[index]);
}


void _union(int p, int c)
{
	int a = max(p,c);
	int b = min(p,c);
	parent[union_find(b)] = union_find(a);
}

//크루스칼 알고리즘. 프림 못해먹겠음.
int kruskal(vector<edge>& edges, int index)
{
	int weight = 0;
	//기저(끝)
	if(index == edges.size())
		return 0;
	
	edge& e = edges.at(index);
	
	//cycle 형성 검사
	if(union_find(e.v1) != union_find(e.v2))
	{
		weight += e.weight;
		//유니온
		_union(e.v1, e.v2);
	}
	return weight + kruskal(edges, index+1);
	
	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//제출할때 제발 꼭 주석처리좀 하고 내서 오답 하나 늘리지 말것 
	freopen("input.txt", "r", stdin);
	
	cin >> V >> E;
	vector<edge> edges;
	for(int i = 0; i<E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(edge(a,b,c));
	}
	//kruskal용 정렬함수. 연산자 오버로딩해서 priority_queue 써도 될 듯.
	sort(edges.begin(), edges.end(), edge_operator);
	cout << kruskal(edges, 0);
	
}
