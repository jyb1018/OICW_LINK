#include <iostream>
#include <vector>

#define MAX 1100000
using namespace std;


int N, M;

int arr[MAX];

int f(int x)
{
	if (arr[x] == x) return x;
	
	return arr[x] = f(arr[x]);
}

void u(int a, int b)
{
	a = f(a); b = f(b);

	arr[a] = b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	while (M--)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd)
		{
			if (f(a) == f(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			u(a, b);
		}
	}

	return 0;
}
