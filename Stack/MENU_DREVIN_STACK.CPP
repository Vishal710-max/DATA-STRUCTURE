#include <iostream>
#define max 5
#include <process.h>
using namespace std;
class stack
{
public:
    int arr[max], top, temp;
    void create(stack *);
    void isfull(stack *);
    void isempty(stack *);
    void push(stack *, int);
    int pop(stack *);
    void sort(stack *);
    void display(stack *);
};
void stack ::create(stack *p)
{
    p->top = -1;
    cout << "stack is created succesfully :";
}
void stack ::isfull(stack *p)
{
    if (p->top == max - 1)
    {
        cout << "stack is full :";
    }
    else
    {
        cout << "stack is not full :";
    }
}
void stack ::isempty(stack *p)
{
    if (p->top == -1)
    {
        cout << "stack is empty :";
    }
    else
    {
        cout << "stack is not empty :";
    }
}
void stack ::push(stack *p, int x)
{
    if (p->top == max - 1)
    {
        cout << "stack overflow......" << endl;
    }
    else
    {
        ++p->top;
        p->arr[p->top] = x;
        cout << "element " << x << "is pushed into stack :" << endl;
    }
}
void stack ::sort(stack *p)
{
    for (int i = 0; i <= p->top; i++)
    {
        for (int j = i + 1; j <= p->top; j++)
        {
            if (p->arr[i] > p->arr[j])
            {
                temp = p->arr[i];
                p->arr[i] = p->arr[j];
                p->arr[j] = temp;
            }
        }
    }
}
int stack ::pop(stack *p)
{
    if (p->top == -1)
    {
        cout << "STACK UNDERFLOWS:";
        return 0;
    }
    else
    {
        p->top--;
        return (p->arr[p->top]);
    }
}
void stack ::display(stack *p)
{
    for (int i = p->top; i >= 0; i--)
    {
        cout << p->arr[i] << "\t";
    }
}
int main()
{
    int ch, x, z;
    stack *p, q;
    p = &q;
    do
    {
        cout << "\n1:Create \n2:Isfull \n3:Isempty \n4:Push \n5:Pop \n6:sort \n7:Display \n8:Exist" << endl;
        cout << "enter the choice :" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.create(p);
            break;

        case 2:
            q.isfull(p);
            break;

        case 3:
            q.isempty(p);
            break;

        case 4:
            cout << "enter the element which you want to push in stack :";
            cin >> x;
            q.push(p, x);
            break;

        case 5:
            z = q.pop(p);
            break;

        case 6:
            q.sort(p);
            cout<<"after sorting :"<<endl;
            q.display(p);
            break;

        case 7:
            q.display(p);
            break;

        case 8:
            exit(1);
        }
    } while (ch != 8);
    return 0;
}