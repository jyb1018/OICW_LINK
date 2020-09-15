//미완

#include <iostream>
#include <queue>


using namespace std;

int N;
int arr[20][20];

int getMax()
{
	int m = -1;
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			m = max(m, arr[i][j]);
	return m;
}

int dfs(int type, int depth)
{
	if(depth == N+1)
		return getMax();
	
	//for(int i = 0; i<depth; i++)
	//	cout << " ";
	//cout << "[IN]" << "type : " << type << " depth : " << depth << "\n";	
	
	//배열복사
	int arr2[20][20];
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			arr2[i][j] = arr[i][j];
	
	//i 행 j 열
	// 0 1 2 3 상 하 좌 우
	if(type == 0)
		for(int j = 0; j<N; j++)
		{
			queue<int> q;
			for(int i = 0; i<N; i++){}
				q.push(arr[i][j]);
			queue<int> q2;
			while(q.size() > 0)
			{
				int f1 = q.front();
				q.pop();
				if(f1 == 0)
					continue;
				if(q.size() > 0 && q.front() == f1)
				{
					q2.push(f1*2);
					q.pop();
					continue;
				}
				q2.push(f1);
			}
			for(int i = 0; q2.size() > 0; i++)
			{
				arr[i][j] = q2.front();
				q2.pop();
			}
		}
	else if(type == 1)
		for(int j = 0; j<N; j++)
		{
			queue<int> q;
			for(int i = N-1; i > 0; i--)
				q.push(arr[i][j]);
			queue<int> q2;
			while(q.size() > 0)
			{
				int f1 = q.front();
				q.pop();
				if(f1 == 0)
					continue;
				if(q.size() > 0 && q.front() == f1)
				{
					q2.push(f1*2);
					q.pop();
					continue;
				}
				q2.push(f1);
			}
			for(int i = N; q2.size() > 0; i--)
			{
				arr[i][j] = q2.front();
				q2.pop();
			}
		}
	else if(type == 2)
		for(int i = 0; i<N; i++)
		{
			queue<int> q;
			for(int j = 0; j<N; j++)
				q.push(arr[i][j]);
			queue<int> q2;
			while(q.size() > 0)
			{
				int f1 = q.front();
				q.pop();
				if(f1 == 0)
					continue;
				if(q.size() > 0 && q.front() == f1)
				{
					q2.push(f1*2);
					q.pop();
					continue;
				}
				q2.push(f1);
			}
			for(int j = 0; q2.size() > 0; j++)
			{
				arr[i][j] = q2.front();
				q2.pop();
			}
		}		
		
	else
		for(int i = 0; i<N; i++)
		{
			queue<int> q;
			for(int j = N-1; j>0; j--)
				q.push(arr[i][j]);
			queue<int> q2;
			while(q.size() > 0)
			{
				int f1 = q.front();
				q.pop();
				if(f1 == 0)
					continue;
				if(q.size() > 0 && q.front() == f1)
				{
					q2.push(f1*2);
					q.pop();
					continue;
				}
				q2.push(f1);
			}
			for(int j = N-1; q2.size() > 0; j--)
			{
				arr[i][j] = q2.front();
				q2.pop();
			}
		}
	
	//for(int i = 0; i<N; i++)
	//{
	//	for(int i = 0; i<depth; i++)
	//		cout << " ";
	//	for(int j = 0; j<N; j++)
	//		cout << arr[i][j] << " ";
	//	cout << "\n";
	//}
			
	
	
	
	int _max = -1;
	for(int i = 0; i<4; i++)
	{
		_max = max(_max, dfs(i, depth+1));
		
		for(int i =0; i<N; i++)
			for(int j = 0; j<N; j++)
				arr[i][j] = arr2[i][j];
	}
	
	
	return _max;
}

int sol()
{
	int** arr2 = new int*[N];
	for(int i = 0; i<N; i++)
	{
		arr2[i] = new int[N];
		for(int j = 0; j<N; j++)
			arr2[i][j] = arr[i][j];
	}
	
	
	int _max = -1;
	for(int i = 0; i<4; i++)
	{
		_max = max(_max, dfs(i, 1));
		for(int i =0; i<N; i++)	
			for(int j = 0; j<N; j++)
				arr[i][j] = arr2[i][j];
	}
	return _max;
}



int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	
	freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			cin >> arr[i][j];
	
	cout << sol();
}
