/*
    Topological Sorting DFS Based Algorithm
*/
#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void DFS(vector<int> adj[], int src, stack<int> &s, bool visited[]){
    visited[src] = true;
    for(int v:adj[src]){
        if(visited[v]==false){
            DFS(adj, v,s,visited);
        }
    }
    s.push(src);
}

void topologicalSort(vector<int> adj[], int V)
{
    stack<int> s;
    bool visited[V] = {false};
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            DFS(adj, u, s, visited);
        }
    }
    
    while(!s.empty()){
        int u=s.top();
        s.pop();
        cout<<u<<" ";
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