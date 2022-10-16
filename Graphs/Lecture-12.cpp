/*
    Topological Sorting Using BFS (Kahn's Algorithm)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void topologicalSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int x : adj[u])
            in_degree[x]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++){
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : adj[u])
            if (--in_degree[x] == 0)
                q.push(x);
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
        addEdgeDirected(adj, u, v);
        cout << "Enter your choice : ";
        cin >> ch;
    }
    printGraph(adj, n);
    topologicalSort(adj, n);
    return 0;
}