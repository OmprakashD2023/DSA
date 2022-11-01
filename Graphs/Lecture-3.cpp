/*
    BFS of an undirected graph
    Given an undirected graph and a source vertex 's' ,print B.F.S. from the given source.
    Time Complexity : O(V+E) where V is the no of vertices and E is the no of edges
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void BFS(vector<int> adj[], int V, int S)
{
    bool visited[V] = {false};
    queue<int> q;
    visited[S] = true;
    q.push(S);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;
    vector<int> adj[n];
    int ch = 1;
    int u, v;
    while (ch)
    {
        cout << "Enter the adjacent vertex : ";
        cin >> u >> v;
        addEdge(adj, u, v);
        cout << "Enter your choice : ";
        cin >> ch;
    }
    printGraph(adj, n);
    int s;
    cout << "Enter the source vertex : ";
    cin >> s;
    BFS(adj, n, s);
    return 0;
}