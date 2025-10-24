#include <iostream>
#define max  50
using namespace std;
class stack { 
public :
int arr[max],top;
void create (stack *);
void push (stack *,int);
int pop (stack *);
};
void stack :: create (stack *p)
{
   p->top=-1;
}
void stack :: push (stack *p,int x){
    if(p->top==max-1){
        cout<<"stack overflow......"<<endl;
    }
    else {
        ++p->top;
        p->arr[p->top]=x;
    }
}
int  stack :: pop (stack *p){
    if(p->top==-1){
        cout<<"element is poped :";
        return 0;
    }
    else{
        return (p->arr[p->top--]);
    }
}

int main ()
{
    char in[50],ch;
    int i=0,temp=0;
    stack ob;
    stack *p,q;
    p=&q;
    ob.create (p);
    cout<<"Enter one infix exp. :"<<endl;
    cin>>in;
    while (in[i]!='\0')
        {
            if (in[i]=='(' || in[i]=='[' || in[i]=='{')
                    {
                        ob.push(p,in[i]);
                    }
            else if (in[i]==')' || in[i]==']' || in[i]=='}')
                    {
                        ch=ob.pop(p);
                        if (ch=='('!=(in[i]==')') || ch=='['!=(in[i]==']')
                            || ch=='{'!=(in[i]=='}'))
                            {
                                    temp=1;
                                    break;
                            }
                    }
            i++;
        }
    if (temp==1 || p->top!=-1)
        {
            cout<<"Exp. is invalid:";
        }
    else 
        {
            cout<<"Exp. is valid :";
        }
    return 0;
}