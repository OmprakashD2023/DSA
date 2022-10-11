/*
    DFS of an undirected graph
*/
#include<bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void DFSRec(vector<int> adj[],int s,bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s]){
        if(visited[u] == false)
            DFSRec(adj,u,visited);
    }
}

void DFS(vector<int> adj[],int V,int S){
    bool visited[V]={false};
    DFSRec(adj,S,visited);
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
    DFS(adj, n, s);
    return 0;
}