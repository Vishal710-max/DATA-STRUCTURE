/*1:one infix exp 2:read char by char 3:if reading char is operator 
then perform 2 times pop operation on stack  4:calculate the value frome reading char and poped char 
and result can be push into stack  5:after reading all exp. make stack empty by pop operation :*/
#include <iostream>
#define max  50
#include<math.h>
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
    char post[max];
    int i=0,val,op1,op2,z;
    stack ob;
    stack *p,q;
    p=&q;
    ob.create (p);
    cout <<"\nEnter the Postfix exp."<<endl;
    cin>>post;
    while (post[i]!='\0')
       {
          if (post[i]=='+' || post[i]=='-' || post[i]=='*' || post[i]=='/'
              || post[i]=='%' || post[i]=='$')
                {
                    op2=ob.pop(p);
                    op1=ob.pop(p);
                    switch (post[i])
                    {
                    
                    case '+':
                    val=op1+op2;
                    ob.push(p,val); 
                    break;
                    
                    case '-':
                    val=op1-op2;   
                    ob.push(p,val);
                    break;

                    case '*':
                    val=op1*op2;   
                    ob.push(p,val);
                    break;

                    case '/':
                    val=op1/op2;   
                    ob.push(p,val);
                    break;

                    case '%':
                    val=op1%op2;   
                    ob.push(p,val);
                    break;

                    case '$':
                    val=pow(op1,op2);
                    ob.push(p,val);   
                    break;

                    }
                }
            else 
               {
                ob.push(p,post[i]-48); 
               }
        i++;
       }
z=ob.pop(p);
cout<<"req. result is :"<<z<<endl;
return 0;
} 