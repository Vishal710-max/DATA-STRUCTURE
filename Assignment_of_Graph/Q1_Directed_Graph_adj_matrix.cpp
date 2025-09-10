// 1) Write a program to represent directed graph using adjacency matrix. 
// -->

#include<iostream>
using namespace std;
int  adj[50][50];

int main () {
    int n, edge, sc, dt;

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

    cout << "\nDirected graph: " << endl;
    for (int i = 1; i <= n; i++, cout << endl) 
        for (int j = 1; j <= edge; j++) 
            cout << "  " << adj[i][j];

}

// Output =>
// Enter number of vertices and edges: 5 5

// Enter source vertex: 1
// Enter destination vertex: 2

// Enter source vertex: 2
// Enter destination vertex: 3

// Enter source vertex: 2
// Enter destination vertex: 4

// Enter source vertex: 3
// Enter destination vertex: 5

// Enter source vertex: 5
// Enter destination vertex: 2

// Directed graph:
//   0  1  0  0  0
//   0  0  1  1  0
//   0  0  0  0  1
//   0  0  0  0  0
//   0  1  0  0  0