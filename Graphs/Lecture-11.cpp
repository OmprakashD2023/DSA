/*
    Detect cycle in a directed graph using DFS
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

bool DFSRec(vector<int> adj[], int src, bool visited[], bool res[])
{
    visited[src] = true;
    res[src] = true;
    for (int x : adj[src])
    {
        if (visited[x] == false && DFSRec(adj, x, visited, res))
        {
            return true;
        }
        else if (res[x] == true)
        {
            return true;
        }
        res[x] = false;
        return false;
    }
}

bool isCyclic(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    bool res[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && DFSRec(adj, i, visited, res))
            return true;
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
    if (isCyclic(adj, n))
        cout << "True";
    else
        cout << "False";
    return 0;
}