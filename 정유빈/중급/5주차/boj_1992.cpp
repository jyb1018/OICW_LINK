//틀렸다는데 반례를 못찾겠는데;

//제발! 제출할 때는! 출력 구문이 섞여 있는지 확인하자 맨이야

#include <iostream>
#include <cstring>

using namespace std;

int arr[64][64];
int N;

int filledWhole(int x, int y, int size)
{
	int prev = arr[x][y];
	for(int i = x; i<x+size; i++)
		for(int j = y; j<y+size; j++)
		{
			cout << "i : " << i << " j : " << j <<endl;
			if(prev != arr[i][j])
				return -1;
			
		}
			return prev;
	
	
}
	
string compress(int fx, int fy, int size)
{
	if(size == 1)
		return to_string(arr[fx][fy]);
	int t = filledWhole(fx, fy, size);

	if(t == 1)
		return "1";
	else if(t == 0)
		return "0";
	
	string temp = "(";
	temp += compress(fx, fy, size/2);
	temp += compress(fx, fy + size/2, size/2);
	temp += compress(fx + size/2, fy, size/2);
	temp += compress(fx + size/2, fy + size/2, size/2);
	
	return temp + ")";
	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	
	cin >> N;
	for(int i = 0; i<N; i++)
	{
		string temp;
		cin >> temp;
		for(int j = 0; j<N; j++)
			arr[i][j] = temp.at(j)-'0';
		
	}
	
	cout << compress(0,0,N);
	

	
}
