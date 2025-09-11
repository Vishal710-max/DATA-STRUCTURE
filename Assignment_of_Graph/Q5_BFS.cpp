// 5) Write a program to implement Breadth first search (BFS) traversal of graph. 
// -->

#include<iostream>
using namespace std;
int  adj[50][50], visited[50], n, edge;

void    BFS(int   start) {
     int queue[50], front = -1, rear = -1;

     queue[++rear] = start;
     cout << "\nBFS => ";

     while (front != rear) {
        int node = queue[++front];
        
        if (!visited[node]) {
            visited[node] = 1;
            cout << "\t" << node;
        
            for (int i = 1; i <= n; i++)
                if (adj[node][i] && !visited[i])
                    queue[++rear] = i;
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
    BFS(start);

    return 0;

}

// Output =>
// Enter number of vertices and edges: 6 8

// Enter source vertex: 1
// Enter destination vertex: 2

// Enter source vertex: 1
// Enter destination vertex: 3

// Enter source vertex: 2
// Enter destination vertex: 6

// Enter source vertex: 3
// Enter destination vertex: 4

// Enter source vertex: 4
// Enter destination vertex: 2

// Enter source vertex: 5
// Enter destination vertex: 1

// Enter source vertex: 6
// Enter destination vertex: 5

// Enter source vertex: 6
// Enter destination vertex: 4

// Enter starting vertex: 1

// BFS =>  1       2       3       6       4       5