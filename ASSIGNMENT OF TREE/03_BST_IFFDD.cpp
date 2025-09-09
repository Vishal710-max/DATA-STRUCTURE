// 3) Write a program to implement binary search tree with following operations- 
//   1) Insert()  2) find_max()  3) find_min()  4) display_even()  5) display_odd() 
// -->

#include<iostream>
using namespace std;

class   node {
    node  *left, *right;
    int   info;
    public:
       node*  create(int);
       void   insert(node*&, int);
       int    find_min(node*);
       int    find_max(node*);
       void   display_even(node*);
       void   display_odd(node*);
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

int  node::find_min(node *temp) {
    if (temp->left)
       return find_min(temp->left);
    return temp->info;
}

int  node::find_max(node *temp) {
    if (temp->right)
       return find_max(temp->right);
    return temp->info;
}

void  node::display_even(node * temp) {
     if (!temp)
        return;
     
     display_even(temp->left);
     if (temp->info % 2 == 0)
        cout << "\t" << temp->info;
     display_even(temp->right);
}

void  node::display_odd(node * temp) {
   if (!temp)
      return;
   
   display_odd(temp->left);
   if (temp->info % 2 != 0)
      cout << "\t" << temp->info;
   display_odd(temp->right);
}

int  main() {
    int ch, ele;
    node obj;
    root = NULL;
 
    do {
       cout << "\n1 : Insert\n2 : Find min\n3 : Find max\n4 : Display Even\n5 : Display Odd\n6 : Exit\nEnter your choice: ";
       cin >> ch;
 
       switch (ch)
       {
          case 1:
             cout << "\nEnter any element: ";
             cin >> ele;
             obj.insert(root, ele);
             break;

          case 2:
             cout << "\nMinimum node: " << obj.find_min(root) << endl;
             break;
          
          case 3:
             cout << "\nMaximum node: " << obj.find_max(root) << endl;
             break;
          
          case 4:
             cout << "\nEven Numbers: ";
             obj.display_even(root);
             break;
          
          case 5:
             cout << "\nOdd Numbers: ";
             obj.display_odd(root);
             break;
          
          case 6:
             cout << "\nExited.." << endl;
             break;   
 
          default:
             cout << "\nWrong Input" << endl;
             break;
       }
    } while (ch != 6);
 
    return 0;
 }

//  Output -->

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 1

// Enter any element: 10

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 1

// Enter any element: 20

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 1

// Enter any element: 13

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 1

// Enter any element: 1

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 2

// Minimum node: 1

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 3

// Maximum node: 20

// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 4

// Even Numbers:   10      20
// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 5

// Odd Numbers:    1       13
// 1 : Insert
// 2 : Find min
// 3 : Find max
// 4 : Display Even
// 5 : Display Odd
// 6 : Exit
// Enter your choice: 6

// Exited..