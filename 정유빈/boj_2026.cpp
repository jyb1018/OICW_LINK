#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

//이 둘이 친구 관계인가
//(앞 인덱스의 정점과 뒷 인덱스의 정점 사이에 간선이 존재 하는가)
int isFriend[901][901] = { 0, };

//이미 검색한 노드일 경우
int isSearched[901] = { 0, };

int main()
{

	ios_base::sync_with_stdio(false);

	FILE* f;
	//freopen_s(&f, "input.txt", "r", stdin);


	int K, N, F;
	cin >> K >> N >> F;
	for (int i = 0; i < F; i++)
	{
		int a, b;
		cin >> a >> b;
		isFriend[a][b] = 1;
		isFriend[b][a] = 1;
	}

	vector<int> v;

	for (int i = 1; i <= N; i++)
	{
		if (isSearched[i] == 1)
			continue;
		v.clear();
		v.push_back(i);
		isSearched[i] = 1;
		for (int j =  1; j <= N; j++)
		{
			if (isFriend[i][j] == 1)
			{
				for (int k = 0; k < v.size(); k++)
				{
					if (isFriend[j][v.at(k)] == 0)		//v[k] 
						break;

					if (k == v.size() - 1)
					{
						v.push_back(j);
						isSearched[j] = 1;
					}

				}
			}

		}
		if (v.size() >= K)
			break;
		
	}

	if (v.size() >= K)
	{
		sort(v.begin(), v.end());
		for (int i = 0; i < K; i++)
			cout << v.at(i) << endl;
	}
	else
		cout << -1 << endl;

}
