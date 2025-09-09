// 2) Write a program to implement binary search tree with following operations- 
//    1) Insert() 2) Count_leaf() 3) Count_total() 4) Search() 
// -->

#include<iostream>
using namespace std;

class   node {
    node  *left, *right;
    int   info;
    public:
       node*  create(int);
       void   insert(node*&, int);
       void   search(node*, int);
       int    count_leaf(node*);
       int    count_total(node*);
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

void   node::search(node *temp, int ele) {
    if (!temp)
       cout << "\nElement Not Found.." << endl;
    else if (temp->info == ele) 
       cout << "\nElement Found.." << endl;
    else 
       search(temp->info > ele? temp->left : temp->right, ele);
    
}

int   node::count_leaf(node* temp) {
    if (!temp) 
        return 0;
    if (!temp->left && !temp->right) 
        return 1;
    return count_leaf(temp->left) + count_leaf(temp->right);
}

int   node::count_total(node* temp) {
    if (!temp) 
       return 0;
    else
       return (1 + count_total(temp->left) + count_total(temp->right));
}

int  main() {
    int ch, ele;
    node obj;
    root = NULL;
 
    do {
       cout << "\n1 : Insert\n2 : Search\n3 : Count Leaf\n4 : Count Total\n5 : Exit\nEnter your choice: ";
       cin >> ch;
 
       switch (ch)
       {
          case 1:
             cout << "\nEnter any element: ";
             cin >> ele;
             obj.insert(root, ele);
             break;
          
          case 2:
             cout << "\nEnter element to search: ";
             cin >> ele;
             obj.search(root, ele);
             break;
 
          case 3:
             cout << "\nTotal Leaf Nodes: " << obj.count_leaf(root) << endl;
             break;
          
          case 4:
             cout << "\nTotal Nodes: " << obj.count_total(root) << endl;
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
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 1

// Enter any element: 20

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 1

// Enter any element: 10

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 1

// Enter any element: 25

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 2

// Enter element to search: 25

// Element Found..

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 3

// Total Leaf Nodes: 2

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 4

// Total Nodes: 3

// 1 : Insert
// 2 : Search
// 3 : Count Leaf
// 4 : Count Total
// 5 : Exit
// Enter your choice: 5

// Exited..