/*
    DFS of an undirected graph
    Time Complexity : O(V+E) where V is the no of vertices and E is the no of edges
*/
#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void DFS(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFS(adj, u, visited);
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
    bool visited[n] = {false};
    DFS(adj, s, visited);
    return 0;
}