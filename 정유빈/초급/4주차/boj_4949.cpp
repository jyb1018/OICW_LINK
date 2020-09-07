#include <iostream>
#include <string>
#include <stack>


//미완성코드임니다

using namespace std;

inline bool isBracelet(char c)
{
	return c == '(' || c == ')' || c == '[' || c == ']';
}

int main()
{
	//입출력 시간 향상
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//입출력 보조
	freopen("input.txt", "r", stdin);
	
	while(!cin.eof())
	{
		string s;
		bool flag = false;
		
		stack<char> st;
		for(int i = 0; i<s.size(); i++)
			if(isBracelet(s.at(i)))
			{
				if(s.at(i) == '(' || s.at(i) == '[')
				{
					if(st.size() == 0 || st.top() == '(' || st.top() == '[')
						st.push(s.at(i));
				}
				else if(s.at(i) == ')' && (st.size() == 0 || st.top() == ']')
					flag = true;
				else if(s.at(i) == ']' && (st.size() == 0 || st.top() == ')')
					flag = true;
				else
					st.pop();
			}
		if(!flag || st.size() != 0)
			cout << "no\n";
		else
			cout << "yes\n";
		
	}
}
