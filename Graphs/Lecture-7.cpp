/*
    DFS of an undirected graph
*/
#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSRec(adj, u, visited);
    }
}

void DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSRec(adj, i, visited);
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
    DFS(adj, n);
    return 0;
}