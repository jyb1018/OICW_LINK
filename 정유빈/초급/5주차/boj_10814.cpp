#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Member
{
public:
    int order;
    int age;
    string name;

    Member(int order, int age, string &name)
        : order(order), age(age), name(name) {}

    bool operator<(Member &m)
    {
        if (age != m.age)
            return age < m.age;
        else
            return order < m.order;
    }
};

ostream &operator<<(ostream &os, Member& m)
{
    os << m.age << " " << m.name;
    return os;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Member> v;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(Member(i, age, name));
    }
    sort(v.begin(), v.end());
    for (Member &c : v)
        cout << c << "\n";
}
