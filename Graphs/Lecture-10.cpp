/*
    Detect cycle in a Graph
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

bool detectCycle(vector <int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (detectCycle(adj, u, visited, s))
                return true;
        }
        else if (u != parent)
            return true;
    }
    return false;
}

bool DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (detectCycle(adj, i, visited, -1))
                return true;
        }
    }
    return false;
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
    if(DFS(adj,n))
        cout<<"True";
    else    
        cout<<"False";
    return 0;
}