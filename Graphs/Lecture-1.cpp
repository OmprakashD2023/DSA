/*
    Adjacency List
*/
#include <bits/stdc++.h>
using namespace std;

//Undirected Graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Directed Graph
void addEdgeDirected(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" -> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}


/*
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
    return 0;
}
*/