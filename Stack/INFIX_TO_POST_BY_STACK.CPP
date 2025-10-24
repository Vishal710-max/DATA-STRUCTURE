/*1:read given infix exp. char by char
  2:if reading char is operator or opening parantheses then add them into stack
  3:if reading char is operend then add them into postfix string
  4:if reading char is closing parantheses then perform repeatedely pop operation
  on stack till it meets the opening parantheses then check poped char if it is not
  parantheses then add them into postfix string
  5:after readig all exp. make stack empty by performing pop operation reapetedly
  into stack and add poped char in postfix string :*/
#include <iostream>
#define max 5
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
    char in[50], post[50], ch;
    int i = 0, j = 0;
    stack ob;
    stack *p, q;
    p = &q;
    ob.create(p);
    cout << "Enter the Infix Exp. =";
    cin >> in;
    while (in[i] != '\0')
    {
        if (in[i] == '(' || in[i] == '+' || in[i] == '-' || in[i] == '*' || 
              in[i] == '/' || in[i] == '%' || in[i] == '^' || in[i] == '$')
        {
            ob.push(p, in[i]);
        }
        else if (in[i] == ')')
        {
            while (p->arr[p->top] != '(')
            {
                ch = ob.pop(p);
                post[j] = ch;
                j++;
            }
            ob.pop(p);
        }
        else
        {
            post[j++] = in[i];
        }
        i++;
    }
    while (p->top != -1)
    {
        ch = ob.pop(p);
        if (ch != '(')
        {
            post[j] = ch;
            j++;
        }
    }
    post[j] = '\0';
    cout << "\n required postfix exp. is =" << post;
    return 0;
}
// Enter the Infix exp. :(p-(a+b)*c)%d
// result :pab+c*-d%
// EX. (A+B)*C=AB+C*