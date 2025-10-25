#include <iostream>
#define max  50
#include<process.h>
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
    char str[max],rev[max];
    int i=0,j=0;
    stack ob;
    stack *p,q;
    p=&q;
    cout<<"enter the string:"<<endl;
    cin>>str;
    ob.create (p);
    while (str[i]!='\0'){
          ob.push(p,str[i]);
          i++;
    }
    while (p->top!=-1){
          rev[j]=ob.pop(p);
          j++;
    }
    rev[j]='\0';
    cout<<"reveresed string is as follows :"<<rev<<endl;
    return 0;
}