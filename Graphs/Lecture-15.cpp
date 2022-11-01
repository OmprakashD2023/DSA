/*
    Articulation Point in an undirected graph
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    void articulationPoint(vector<int> adj[], int u, bool visited[], int disc[], int low[], int &time, int parent, bool isAP[]);

public:
    Graph(int V);
    void addEdge(vector<int> adj[], int u, int v);
    void AP(vector<int> adj[]);
};

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::articulationPoint(vector<int> adj[], int u, bool visited[], int disc[], int low[], int &time, int parent, bool isAP[])
{
    int children = 0;

	visited[u] = true;

	disc[u] = low[u] = ++time;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			articulationPoint(adj, v, visited, disc, low, time, u, isAP);

			low[u] = min(low[u], low[v]);

			if (parent != -1 && low[v] >= disc[u])
				isAP[u] = true;
		}

		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}

	if (parent == -1 && children > 1)
		isAP[u] = true;
}

void Graph::AP(vector<int> adj[])
{
    int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool isAP[V] = { false };
	int time = 0, par = -1;

	for (int u = 0; u < V; u++)
		if (!visited[u])
			articulationPoint(adj, u, visited, disc, low,
				time, par, isAP);

	for (int u = 0; u < V; u++)
		if (isAP[u] == true)
			cout << u << " ";
}

int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;
    int ch = 1;
    int u, v;
    vector<int> adj[n];
    Graph g(n);
    while (ch)
    {
        cout << "Enter the adjacent vertex : ";
        cin >> u >> v;
        g.addEdge(adj,u, v);
        cout << "Enter your choice : ";
        cin >> ch;
    }
    g.AP(adj);
    return 0;
}