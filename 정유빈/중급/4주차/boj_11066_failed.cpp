/*
X1 = C2 + C3 
X2 = C1 + X1
X4(최종) = C1 + X1
 
N개의 파일을 한개로 합치는 활동(무조건 두개를 하나로 합치는 걸 반복)
그때의 최소 비용 출력
C <=500
size <= 10000

그냥 그 때의 가장 작은 두개를 골라서 하면 될듯.

순서 바꾸면 안됨...(정렬 하면 안됨) 하 다해놓고 뭔가했네

결국 보니까 토너먼트 모든 경우 짜는 문제.

최악 : 10000*500*log_2(500) < 2^32-1

dp 어떻게 쓰지...
O(2^K)
*/


#include <iostream>
#include <list>

using namespace std;


list<int> file_size;
int cache[500][500][500];

int K;


// 실패 사유 : dp 어떻게 쓸지 감이 안잡힘
int func(int depth)
{
	//기저 : 끝
	if(depth == K-1)
		return 0;
	
	int _min = 2147483647;
	
	for(int i = 0; i<file_size.size()-1; i++)
	{
		int temp1 = *next(file_size.begin(), i);
		int temp2 = *next(file_size.begin(), i+1);
		int sum = temp1 + temp2;
		
		// for(int j = 0; j<depth; j++)
		// 	cout << "  ";
		// cout << temp1 << " " << temp2 << endl;
		
		file_size.erase(next(file_size.begin(), i));
		file_size.erase(next(file_size.begin(), i));
		
		file_size.insert(next(file_size.begin(), i), sum);
		
		_min = min(_min, sum + func(depth+1)); 
		
		file_size.erase(next(file_size.begin(), i));
		
		file_size.insert(next(file_size.begin(), i), temp2);
		file_size.insert(next(file_size.begin(), i), temp1);
	}
	
	// for(int j = -1; j<depth; j++)
	// 		cout << "  ";
	// cout << _min << endl;
	
	return _min;
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//input
	freopen("input.txt", "r", stdin);
	
	int T;
	cin >> T;
	while(T-->0)
	{
		cin >> K;
		for(int i = 0; i<K; i++)
		{
			int temp;
			cin >> temp;
			file_size.push_back(temp);
		}

		
		cout << func(0) << "\n";
		
	}
}
