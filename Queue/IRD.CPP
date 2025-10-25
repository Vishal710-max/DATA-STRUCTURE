//the terms which is replaced in IRD and ORD is front=left rear=right 
#include<iostream>
using namespace std;
#define max  5
#include <process.h> 
class queue 
{
    int item[max],left,right;
    public :
        void create (queue *);
        void insert (queue*,int);
        int rem_left (queue*);
        int rem_right(queue *);
        void display (queue*);
};
void queue :: create (queue *p)
{
    p->left=p->right=-1;
}
void queue :: insert (queue *p,int x)
{ 
    if (p->right==max-1){
        cout<<"\nIRD is overflows....";
    }
    else{
        ++p->right;
        p->item[p->right]=x;
        cout<<"\nlement is inserted..."<<x;
    }
}
int queue :: rem_left (queue *p)
{
    if (p->left==p->right){
        cout<<"\nQueue underflows...";
    }
    else{
        ++p->left;
        return (p->item[p->left]);
    }
}
int queue :: rem_right (queue *p)
{
    if (p->left==p->right){
        cout<<"\nQueue underflows...";
    }
    else{
        return (p->item[p->right--]);
    }
}
void queue :: display (queue *p)
{
    for (int i=p->left+1;i<=p->right;i++){
        cout<<"\t"<<p->item[i];
    }
}
int main ()
{
    queue *p,q,ob;
    p=&q;
    int ch,x,z;
    do {
    cout<<"\n1:create\n2:Insert\n3:Remove left\n4:remove right\n5:display\n6:Exit\nEnter the choice";
    cin>>ch;
    switch (ch)
    {
        case 1:
            ob.create (p);
            break;
        case 2:
            cout<<"\nEnter the element";
            cin>>x;
            ob.insert(p,x);
            break;
        case 3:
            z=ob.rem_left(p);
            cout<<"\nelement is removed"<<z;
            break;

        case 4:
            z=ob.rem_right(p);
            cout<<"\nelement is removed"<<z;
            break;

        case 5:
            ob.display (p);
            break;
        case 6:
            exit (1);
        default :
            cout<<"\nwrong input";
            break;
    }
}while (ch!=6);
return 0;
}