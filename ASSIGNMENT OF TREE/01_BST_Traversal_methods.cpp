// 1) Write a program to implement binary search tree with tree traversal methods.
// -->

#include<iostream>
using namespace std;

class   node {
    node  *left, *right;
    int   info;
    public:
       node*  create(int);
       void   insert(node*&, int);
       void   inorder(node*);
       void   preorder(node*);
       void   postorder(node*);
} *root;

node*  node::create(int ele) {
     node *newNode = new node;
     newNode->left = newNode->right = NULL;
     newNode->info = ele;
     return  newNode;
}

void  node::insert(node *&temp, int ele) {
     if (!temp) 
       temp = create(ele);
     else 
       insert(temp->info > ele? temp->left : temp->right, ele);
}

void node::inorder(node *temp) {
  if (!temp) return;
  inorder(temp->left);
  cout << "\t" << temp->info;
  inorder(temp->right);
}

void  node::preorder(node *temp) {
  if (temp == NULL) return;
  cout << "\t" << temp -> info;
  preorder(temp -> left);
  preorder(temp -> right);
}

void  node::postorder(node *temp) {
  if (temp == NULL) return;
  postorder(temp -> left);
  postorder(temp -> right);
  cout << "\t" << temp -> info;
}


int  main() {
  int ch, ele;
  node obj;
  root = NULL;

  do {
     cout << "\n1 : Insert\n2 : Preorder\n3 : Inorder\n4 : Postorder\n5 : Exit\nEnter your choice: ";
     cin >> ch;

     switch (ch)
     {
        case 1:
           cout << "\nEnter any element: ";
           cin >> ele;
           obj.insert(root, ele);
           break;
        
        case 2:
           obj.preorder(root);
           break;
        
        case 3:
           obj.inorder(root);
           break;
        
        case 4:
           obj.postorder(root);
           break;
        
        case 5:
           cout << "\nExited.." << endl;
           break;
        
        default:
           cout << "\nWrong Input" << endl;
           break;
     }
  } while (ch != 5);

  return 0;
}


// Output -->

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 8

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 10

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 14

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 3

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 6

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 13

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 1

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 7

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 1

// Enter any element: 4

// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 2
//         8       3       1       6       4       7       10      14      13
// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 3
//         1       3       4       6       7       8       10      13      14
// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 4
//         1       4       7       6       3       13      14      10      8
// 1 : Insert
// 2 : Preorder
// 3 : Inorder
// 4 : Postorder
// 5 : Exit
// Enter your choice: 5

// Exited..
