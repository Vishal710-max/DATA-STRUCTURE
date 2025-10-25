//1) Write a program to implement stack by using array. (Static
//Implementation of stack) 
//--> 
#include<iostream> 
using namespace std;
class stack 
{ 
int *items, top, size;
public: 
void create(stack*, int); 
void push(stack*, int); 
int pop(stack*); 
void isempty(stack*); 
void isfull(stack*); 
void display(stack*); 
};
void stack::create(stack *p, int size) 
{ 
p-> top = -1;
p-> items = new int[size];
p-> size = size;
cout << "\nStack is created.." << endl; 
} 
void stack::push(stack *p, int ele) 
{ 
if(p->top == p->size-1) { 
cout << "\nStack overflows.." << endl; 
} 
else { 
p-> items[++p->top] = ele; 
cout << "\nElement "<<ele<<"Pushed" << endl; 
} 
} 
int stack::pop(stack *p)
{ 
if (p-> top == -1) { 
cout << "\nStack underflows.." << endl;
return 0;
} 
else { 
return p-> items[p-> top--];
} 
} 
void stack::isfull(stack *p) 
{ 
if (p->top == p-> size-1){
cout << "\nStack is FULL" << endl; 
} 
else { 
cout << "\nStack is NOT FULL" << endl; 
} 
} 
void stack::isempty(stack *p)
{ 
if (p-> top == -1){ 
cout << "\nStack is EMPTY" << endl; 
} 
else { 
cout << "\nStack is NOT EMPTY" << endl; 
} 
} 
void stack::display(stack *p)
{ 
cout << "\nElements: ";
for (int i = p->top; i >= 0; i--) {
cout << p->items[i] << " ";
} 
if (p-> top == -1){ 
cout << "0" << endl; 
} 
} 
int main() 
{ 
stack obj,q;
stack *p = &q; 
int ch, size, ele;
do
{ 
cout <<"\n1 : Create\n2 : Isfull\n3 : Isempty\n4 : Push\n5 :Pop\n6 : Dispaly\n7 : Exit\nEnter your choice: ";
cin >> ch;
switch (ch) 
{ 
case 1:
cout << "\nEnter the size of stack: ";
cin >> size; 
obj.create(p, size);
break; 
case 2:
obj.isfull(p);
break; 
case 3:
obj.isempty(p);
break; 
case 4:
cout << "\nEnter element to push: ";
cin >> ele; 
obj.push(p, ele);
break; 
case 5:
cout << "\nPopped element: " << obj.pop(p) << endl;
break; 
case 6:
obj.display(p);
break; 
} 
} while (ch != 7);
return 0;
} 
