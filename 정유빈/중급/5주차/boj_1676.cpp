//생각보다도 과하게 쉬웠음

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int two = 0;
	int five = 0;
	
	for(int i = 1; i<=N; i++)
	{
		int temp = i;
		while(temp % 2 == 0)
		{
			temp /= 2;
			two++;
		}
		while(temp % 5 == 0)
		{
			temp /= 5;
			five++;
		}
	}
	cout << min(two, five);
}
