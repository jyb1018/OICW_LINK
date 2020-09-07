
#include <iostream>

using namespace std;

int N;
//int dp[16][16];
int board[16][16]; // 0 빈칸 -1 queen 1~8 공격가능 -2 벽
void testboard()
{
    for(int i = 0; i<N+2; i++)
    {
        for(int j = 0; j<N+2; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
void queenOnBoard(int x, int y, int inout) //inout 1 in -1 out
{

    for (int i = x + 1; board[i][y] != -2; i++)
        if (board[i][y] != -1)
            board[i][y] += inout;
    for (int i = x - 1; board[i][y] != -2; i--)
        if (board[i][y] != -1)
            board[i][y] += inout;
    for (int i = y + 1; board[x][i] != -2; i++)
        if (board[x][i] != -1)
            board[x][i] += inout;
    for (int i = y - 1; board[x][i] != -2; i--)
        if (board[x][i] != -1)
            board[x][i] += inout;

    for (int i = x + 1, j = y + 1; board[i][j] != -2; i++, j++)
        if (board[i][j] != -1)
            board[i][j] += inout;
    for (int i = x + 1, j = y - 1; board[i][j] != -2; i++, j--)
        if (board[i][j] != -1)
            board[i][j] += inout;
    for (int i = x - 1, j = y + 1; board[i][j] != -2; i--, j++)
        if (board[i][j] != -1)
            board[i][j] += inout;
    for (int i = x - 1, j = y - 1; board[i][j] != -2; i--, j--)
        if (board[i][j] != -1)
            board[i][j] += inout;

	
	//cout << "x : " << x << " y : " << y << endl;
    if (inout == 1)
        board[x][y] = -1;
    else
        board[x][y] = 0;
}

int dfs(int x, int y, int depth)
{
    if (board[x][y] != 0)
        return 0;
    if (depth == N)
        return 1;

    queenOnBoard(x, y, 1);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += dfs(x + 1, i + 1, depth + 1);
		
    }
	queenOnBoard(x , y, -1);
    return sum;
}

int nqueen()
{
    if (N == 1)
        return 1;

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += dfs(1, i + 1, 1);

    return sum;
}

void init()
{
    cin >> N;

    for (int i = 0; i < N + 2; i++)
        board[0][i] = -2;
    for (int i = 1; i < N + 1; i++)
        board[i][0] = board[i][N + 1] = -2;
    for (int i = 0; i < N + 2; i++)
        board[N + 1][i] = -2;
}

int main()
{
    init();
    cout << nqueen();
}
