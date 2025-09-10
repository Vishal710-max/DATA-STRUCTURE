// 3) Write a program to represent weighted directed graph using adjacency matrix. 
// -->

#include<iostream>
using namespace std;
int  adj[50][50];

int main () {
    int n, edge, sc, dt, w;

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
            cout << "Enter weight: ";
            cin >> w;
            adj[sc][dt] = w;
        }
    }

    cout << "\nAdjacency matrix of Weighted graph: " << endl;
    for (int i = 1; i <= n; i++, cout << endl) 
        for (int j = 1; j <= edge; j++) 
            cout << "  " << adj[i][j];

}

// Output =>
// Enter number of vertices and edges: 4 4

// Enter source vertex: 1
// Enter destination vertex: 2
// Enter weight: 5

// Enter source vertex: 2
// Enter destination vertex: 4
// Enter weight: 2

// Enter source vertex: 4
// Enter destination vertex: 1
// Enter weight: 3

// Enter source vertex: 4
// Enter destination vertex: 3
// Enter weight: 4

// Adjacency matrix of Weighted graph:
//   0  5  0  0
//   0  0  0  2
//   0  0  0  0
//   3  0  4  0