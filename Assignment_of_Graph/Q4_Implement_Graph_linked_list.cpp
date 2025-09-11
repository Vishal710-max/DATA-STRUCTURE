// 4) Write a program to implement graph using linked list with all basic operations.
// -->

#include <iostream>
using namespace std;

class edge {
public:
    int dest;
    edge *right;
    edge(int ele) {
        dest = ele;
        right = NULL;
    }
};

class node {
    int info;
    node *next;
    edge *adj;

public:
    node *create(int);
    void insert_vertex(node *&, int);
    void display_vertex(node *);
    int search(node *, int);
    void insert_edge(int, int);
    void display_edge(int);
    void display_graph();
} *start;

node *node::create(int ele) {
    node *p = new node;
    p->next = NULL;
    p->info = ele;
    p->adj = NULL;
    return p;
}

void node::insert_vertex(node *&first, int ele) {
    if (!first) {
        first = create(ele);
        cout << "\nVertex is inserted.." << endl;
        return;
    }
    insert_vertex(first->next, ele);
}

void node::display_vertex(node *temp) {
    if (temp) {
        cout << "\t" << temp->info;
        display_vertex(temp->next);
    }
}

int node::search(node *temp, int srch) {
    if (!temp)
        return 0;

    if (temp->info == srch)
        return 1;
    return search(temp->next, srch);
}

void node::insert_edge(int src, int dest) {     
    if (!search(start, src) || !search(start, dest)) {
        cout << "\nInvalid vertex.." << endl;
        return;
    }

    node *p = start;
    while (p && p->info != src)  p = p->next;

    if (!p->adj) p->adj = new edge(dest);

    else {
        edge *temp = p->adj;
        while (temp->right) temp = temp->right;
        temp->right = new edge(dest);
    }
    cout << "\nEdge is created.." << endl;
}

void node::display_edge(int ele) {
    if (!search(start, ele)) {
        cout << "\nVertex not found.." << endl;
        return;
    }

    for (node *p = start; p; p = p->next) {
        if (p->info == ele) {
            if (!p->adj) {
                cout << "\nNo any edge.." << endl;
                return;
            }
            cout << "\nEdges:\n";
            for (edge *temp = p->adj; temp; temp = temp->right)
                cout << p->info << " --> " << temp->dest << endl;
            return;
        }
    }
}

void node::display_graph() {
     if (!start) {
       cout << "\nNo any vertex.." << endl;
       return;
     }

     node *p = start;
    
     cout << "\nGraph: " << endl;
     while (p) {
        cout << p->info;
        edge *temp = p->adj;
        while (temp) {
            cout << " --> " << temp->dest;
            temp = temp->right;
        }
        
        cout << endl;
        p = p->next; 
     }
     
}

int main() {
    node obj;
    int ele, ch, src, dest;
    edge *temp;

    do {
        cout << "\n1: Insert vertex\n2: Display vertex\n3: Search\n4: Insert edge\n5: Display edge\n6: Display Graph\n7: Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nEnter vertex: ";
            cin >> ele;
            obj.insert_vertex(start, ele);
            break;

        case 2:
            cout << "\nVertices: ";
            obj.display_vertex(start);
            break;

        case 3:
            cout << "\nEnter search vertex: ";
            cin >> ele;
            cout << (obj.search(start, ele) ? "\nVertex is found.." : "\nVertex is not found..") << endl;
            break;

        case 4:
            cout << "\nEnter source edge: ";
            cin >> src;
            cout << "Enter dest vertex: ";
            cin >> dest;
            obj.insert_edge(src, dest);
            break;

        case 5:
            cout << "\nEnter vertex to display edges: ";
            cin >> ele;
            obj.display_edge(ele);
            break;

        case 6:
            obj.display_graph();
            break;
        
        case 7:
            cout << "Exited..\n";
            break;

        default:
            cout << "\nInvalid choice..." << endl;
        }
    } while (ch != 7);

    return 0;
}

// Output =>
// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 1

// Enter vertex: 10

// Vertex is inserted..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 1

// Enter vertex: 20

// Vertex is inserted..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 1

// Enter vertex: 30

// Vertex is inserted..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 1

// Enter vertex: 40

// Vertex is inserted..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 2

// Vertices:       10      20      30      40
// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 4

// Enter source edge: 10
// Enter dest vertex: 40

// Edge is created..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 4

// Enter source edge: 20
// Enter dest vertex: 30

// Edge is created..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 4

// Enter source edge: 20
// Enter dest vertex: 40

// Edge is created..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 4 

// Enter source edge: 20
// Enter dest vertex: 10

// Edge is created..

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 6

// Graph:
// 10 --> 40
// 20 --> 30 --> 40 --> 10
// 30
// 40

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 5

// Enter vertex to display edges: 20

// Edges:
// 20 --> 30
// 20 --> 40
// 20 --> 10

// 1: Insert vertex
// 2: Display vertex
// 3: Search
// 4: Insert edge
// 5: Display edge
// 6: Display Graph
// 7: Exit
// Enter choice: 7
// Exited..