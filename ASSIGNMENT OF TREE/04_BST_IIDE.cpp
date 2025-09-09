// 4) Write a menu dr iven program that deletes node from binary search tree. 
// Hint: Menu will look like- 
//     1) Insert 
//     2) Inorder 
//     3) Delete 
//     4) Exit
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
       void   del_leaf(node*, node*);
       void   del_one(node*, node*);
       void   del_two(node*);
       void   del(int);
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

void  node::inorder(node *temp) {
    if (!temp) return;
    inorder(temp->left);
    cout << "\t" << temp->info;
    inorder(temp->right);
}

void  node::del_leaf(node *child, node *parent) {
    (parent->left == child)? parent->left = NULL : parent->right = NULL;
    delete child;
}

void  node::del_one(node *child, node *parent) {
    
    node *&link = (child == parent->left)? parent->left : parent->right;
    link = (child->left)? child->left : child->right;
  
}

void  node::del_two(node *child) {
    node *parent = child, *lft = child->left;

    while (lft->right) {
         parent = lft;
         lft = lft->right;
    }
    child->info = lft->info;
    (lft->left || lft->right) ? del_one(lft, parent) : del_leaf(lft, parent);

}

void node::del(int ele) {
  node *parent = NULL, *child = root;

  while (child && child->info != ele) {
      parent = child;
      child = (ele > child->info) ? child->right : child->left;
  }

  if (!child) {
      cout << "\nNode Not found..\n";
      return;
  }

  (!child->left && !child->right) ? del_leaf(child, parent) : 
  (child->left && child->right) ? del_two(child) : del_one(child, parent);
} 

int  main() {
    int ch, ele;
    node obj;
    root = NULL;
 
    do {
       cout << "\n1 : Insert\n2 : Inorder\n3 : Delete\n4 : Exit\nEnter your choice: ";
       cin >> ch;
 
       switch (ch)
       {
          case 1:
             cout << "\nEnter any element: ";
             cin >> ele;
             obj.insert(root, ele);
             break;
          
          case 2:
             obj.inorder(root);
             break;
          
          case 3:
             cout << "\nEnter element to delete: ";
             cin >> ele;
             obj.del(ele);
             break;
          
          case 4:
             cout << "\nExited.." << endl;
             break;
          
 
          default:
             cout << "\nWrong Input" << endl;
             break;
       }
    } while (ch != 4);
 
    return 0;
 }
 
 
// Output -->

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 8

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 10

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 14

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 3

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 6

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 13

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 1

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 7

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 1

// Enter any element: 4

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 2
//         1       3       4       6       7       8       10      13      14
// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 3

// Enter element to delete: 1

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 2
//         3       4       6       7       8       10      13      14
// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 3

// Enter element to delete: 13

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 2
//         3       4       6       7       8       10      14
// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 3

// Enter element to delete: 4

// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 2
//         3       6       7       8       10      14
// 1 : Insert
// 2 : Inorder
// 3 : Delete
// 4 : Exit
// Enter your choice: 4

// Exited..