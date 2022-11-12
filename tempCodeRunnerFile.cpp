#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *l;
    bool *visited;
public:
    Graph(int x)
    {
        v = x;
        l = new list<int>[v];
        visited= new bool[v];
    }
    void addEdge(int u, int v, bool di)
    {
        l[u].push_back(v);
        if (!di)
        {
            l[v].push_back(u);
        }
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (auto nbr : l[i])
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
    void dfs(int src)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto nbr : l[src])
        {
            if (visited[nbr] == false)
            {
                dfs(nbr);
            }
        }
    }
    void bfs(int src){
        queue<int> q;
        for(int i =0;i<v;i++){
            visited[i]=false;
        }
        visited[src]=true;
        q.push(src);
        while(!q.empty()){
            int x = q.front();
            cout<<x<<" ";
            q.pop();
            for(int nbr:l[x]){
                if(visited[nbr]==false){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }

};
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 0, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 2, 0);
    g.print();
    cout<<"DFS"<<endl;
    g.dfs(0);
    cout<<endl<<"BFS"<<endl;
    g.bfs(0);
    return 0;
}