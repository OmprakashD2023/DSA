/*
    Adjacency Matrix
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;
    int arr[n][n] = {0};
    int ch = 1;
    int u, v;
    if (n != 1)
    {
        while (ch)
        {
            cout << "Enter the adjacent vertex : ";
            cin >> u >> v;
            arr[u][v] = 1;
            arr[v][u] = 1;
            cout << "Enter your choice : ";
            cin >> ch;
        }
    }
    cout << "    ";
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}