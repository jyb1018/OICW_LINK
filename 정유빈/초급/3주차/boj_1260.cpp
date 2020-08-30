#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int matrix[1001][1001] = {0,};
int visited[1001] = {0,};

void dfs(int n) 
{
    visited[n] = 1;
    cout << n << " ";
    for(int i = 1; i<=N; i++)
    {
        if(matrix[n][i] == 1 && visited[i] == 0)
            dfs(i);
        
    }
}


void bfs(queue<int>& q) 
{
    if(q.size() == 0)
        return;
    int n = q.front();
    q.pop();
    if(visited[n] != 1)
    {
        visited[n] = 1;
        cout << n << " ";
    }
    for(int i = 1; i<=N; i++)
        if(matrix[n][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            cout << i << " ";
            q.push(i);
        }
    bfs(q);
            
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> V;
    for(int i = 0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = matrix[b][a] = 1;
    }
    dfs(V);
    cout << endl;
    fill(visited, visited+1002, 0);
    queue<int> q;
    q.push(V);
    bfs(q);
}
