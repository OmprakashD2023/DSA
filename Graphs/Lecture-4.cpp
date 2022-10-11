/*
    BFS of a disconnected graph
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void BFS(vector<int> adj[], int S,bool visited[])
{
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

void BFSD(vector<int> adj[],int V){
    bool visited[V]={false};
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            BFS(adj,i,visited);
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
    BFSD(adj, n);
    return 0;
}