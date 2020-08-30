#include <iostream>

using namespace std;

char plate[50][50];
int N, M;
int _min = 2500;

int getRecoloringPlates(int x, int y, int mode)
{
    int sum = 0;
    for (int i = x; i < x + 8; i++)
        for (int j = y; j < y + 8; j++)
        {
            if (plate[i][j] != ((i + j + mode) % 2 == 0 ? 'W' : 'B'))
                if (++sum > _min)
                    return _min;
        }
    return sum;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    getchar();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            plate[i][j] = getchar();
        getchar();
    }
    for (int i = 0; i < N - 7; i++)
        for (int j = 0; j < M - 7; j++)
        {
            _min = min(_min, getRecoloringPlates(i, j, 0));
            _min = min(_min, getRecoloringPlates(i, j, 1));
        }
    cout << _min;
}
