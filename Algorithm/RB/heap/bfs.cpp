#include <bits/stdc++.h>
using namespace std;

int graph[10][10];
int Vertex, Edge, Source, Destination, s, visited;
void BFS(int Starting_Vertex, int n)
{
    for (int i = 0; i <= n; i++)
        int visited[i] = {0};
    queue<int> Q;
    Q.push(s);
    int visited[s] = {1};

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
    }
}

int main()
{

    cout << "Number of vertexes:\n ";
    cin >> Vertex;
    cout << "Number of edges:\n ";
    cin >> Edge;
    cout << "Input of every edges:\n ";
    for (int i = 1; i <= Edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    cout << "Enter Source:\n ";
    cin >> Source;
    cout << "Enter Destination:\n ";
    cin >> Destination;
    void BFS();
    for (int i = 1; i <= Vertex; i++)
    {
        for (int j = 1; j <= Vertex; j++)
        {
            cout << graph[i][j] << '\t';
        }
        cout << "\n";
    }

    return 0;
}
