#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long N, P, Q;
vector<pair<int, long long>> v;

int v_contains(int n)
{
	for(int i = 0; i<v.size(); i++)
		if(v.at(i).first == n)
			return i;
	return -1;
}

long long dp(long long n)
{
	int index;
	if((index = v_contains(n)) != -1)
		return v.at(index).second;
	v.push_back(pair<int, long long>(n,dp(n/P) +dp(n/Q)));
	return (v.end()-1)->second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	v.push_back(pair<int, long long>(0,1));
	
	cin >> N >> P >> Q;
	cout << dp(N);
	
}


//되게 좋은 문제 같은데
