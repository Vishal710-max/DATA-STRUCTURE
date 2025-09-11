// 6) Write a program to implement Depth first search (DFS) traversal of graph.
// -->

#include<iostream>
using namespace std;
int  adj[50][50], visited[50], n, edge;

void    DFS(int   start) {
     int stack[50], top = -1;

     stack[++top] = start;
     cout << "\nDFS => ";

     while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = 1;
            cout << "\t" << node;

            for (int i = n; i >= 1; i--)
                if (adj[node][i] && !visited[i]) 
                    stack[++top] = i;
        }
     }
     cout << endl;
}

int main () {
    int sc, dt, start;

    cout << "\nEnter number of vertices and edges: ";
    cin >> n >> edge;

    for (int i = 1; i <= edge; i++) {
        cout << "\nEnter source vertex: ";
        cin >> sc;
        cout << "Enter destination vertex: ";
        cin >> dt;

        if (sc > n || dt > n || sc <= 0 || dt <= 0) {
            cout << "\nInvalid vertices.." << endl;
            i--;
        } 
        else {
            adj[sc][dt] = 1;
        }
    }

    cout << "\nEnter starting vertex: ";
    cin >> start;
    DFS(start);

    return 0;
}

// Output =>
// Enter number of vertices and edges: 6 8

// Enter source vertex: 2
// Enter destination vertex: 1

// Enter source vertex: 2
// Enter destination vertex: 5

// Enter source vertex: 3
// Enter destination vertex: 1

// Enter source vertex: 3
// Enter destination vertex: 6

// Enter source vertex: 4
// Enter destination vertex: 3

// Enter source vertex: 5
// Enter destination vertex: 4

// Enter source vertex: 5
// Enter destination vertex: 6

// Enter source vertex: 6
// Enter destination vertex: 2

// Enter starting vertex: 3

// DFS =>  3       1       6       2       5       4