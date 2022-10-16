/*
    Shortest path in an Unweighted graph
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

vector<int> shortestPath(vector<int> adj[], int S, int V)
{
    queue<int> q;
    vector<int> dist(V, 0);
    bool visited[V] = {false};
    visited[S] = true;
    q.push(S);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return dist;
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
    vector<int> dist = shortestPath(adj, s, n);
    for(auto i:dist){
        cout<<i<<" ";
    }
    return 0;
}