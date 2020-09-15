#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int num = 0, sum = 0;
    bool on_bracelet = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) >= '0' && s.at(i) <= '9')
        {
            num *= 10;
            num += s.at(i) - '0';
        }
        else if (on_bracelet)
        {
            sum -= num;
            num = 0;
        }
        else
        {
            sum += num;
            num = 0;
            if (s.at(i) == '-')
                on_bracelet = true;
        }
    }
    if (on_bracelet)
        cout << sum - num;
    else
        cout << sum + num;
}
