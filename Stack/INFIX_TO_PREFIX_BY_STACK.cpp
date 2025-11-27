// Enter the Infix exp. :(a+b)*C
// result : *+abC

#include <iostream>
#define max 50
#include <string.h>
using namespace std;
class stack
{
public:
    int arr[max], top;
    void create(stack *);
    void push(stack *, int);
    int pop(stack *);
};
void stack ::create(stack *p)
{
    p->top = -1;
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
    }
}
int stack ::pop(stack *p)
{
    if (p->top == -1)
    {
        cout << "element is poped :";
        return 0;
    }
    else
    {
        return (p->arr[p->top--]);
    }
}

int main()
{
    char in[max], pre[max], ch;
    int i = 0, j = 0;
    stack ob;  
    stack *opst, *oprnd, a, b;
    opst = &a;
    oprnd = &b;
    ob.create(opst);
    ob.create(oprnd);
    cout << "Enter the one infix exp. =";
    cin >> in;
    strrev(in);
    while (in[i] != '\0')
    {
        if (in[i] == ')' || in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '%' || in[i] == '^' || in[i] == '$')
        {
            ob.push(opst, in[i]);
        }

        else if (in[i] == '(')
        {
            while (opst->top != -1)
            {
                ch = ob.pop(opst);
                if (ch != ')')
                {
                    ob.push(oprnd, ch);
                }
            }
        }

        else
        {
            ob.push(oprnd, in[i]);
        }
        i++;
    }
    if (opst->top != -1)
    {
        ch = ob.pop(opst);
        if (ch != ')')
        {
            ob.push(oprnd, ch);
        }
    }
    while (oprnd->top != -1)
    {
        pre[j] = ob.pop(oprnd);
        j++;
    }
    pre[j] = '\0';
    cout << "required prefix exp. is :" << pre << endl;
    return 0;

}  
