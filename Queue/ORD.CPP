#include<iostream>
using namespace std;
#define max  5
#include <process.h> 
class queue 
{
    int item[max],left,right;
    public :
        void create (queue *);
        void ins_left (queue*,int);
        void ins_right (queue *,int);
        int remove (queue *); 
        void display (queue*);
};
void queue :: create (queue *p)
{
    p->left=p->right=-1;
}
void queue :: ins_left (queue *p,int x)
{
    if (p->right==max-1){
        cout<<"\nORD overflows...";
    }
    else{
        for (int i=p->right+1;i>=p->left+2;i--){
            p->item[i]=p->item[i-1];
        }
        p->item[p->left+1]=x;
        ++p->right;
        cout<<"\nElement is inserted :"<<x;
    }
}
void queue :: ins_right (queue *p,int x)
{
    if (p->right==max-1){
        cout<<"\nORD overflows...";
    }
    else{
        ++p->right;
        p->item[p->right]=x;
        cout<<"\nElement is inserted:"<<x;
    }
}
int queue :: remove(queue *p)
{
    if (p->left==p->right){
        cout<<"\nQueue underflows...";
        return 0;
    }
    else{
        ++p->left;
        return (p->item[p->left]);
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
    int ch,x,z,pr;
    do {
    cout<<"\n1:create\n2:Insert left\n3:insert right\n4:remove\n5:display\n6:Exit\nEnter the choice";
    cin>>ch;
    switch (ch)
    {
        case 1:
            ob.create (p);
            break;
        case 2:
            cout<<"\nEnter the element";
            cin>>x;
            ob.ins_left(p,x);
            break;
        case 3:
            cout<<"\nEnter the element";
            cin>>x;
            ob.ins_right(p,x);
            break;

        case 4:
            z=ob.remove (p);
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