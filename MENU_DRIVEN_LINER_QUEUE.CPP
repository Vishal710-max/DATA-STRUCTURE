#include <iostream>
using namespace std;
#include <process.h>
#define  max 5
class queue
{
    int item[max],front,rear;
    public :
        void create (queue*);
        void isempty (queue*);
        void isfull (queue*);
        void insert (queue*,int);
        int remove (queue*);
        void display (queue*);
};
void queue :: create (queue *q)
{
    q->front=-1;
    q->rear=-1;
    cout<<"\nQueue is created :";
}
void queue :: isempty (queue *q)
{
    (q->front==q->rear)?cout<<"\nQueue is empty...":cout<<"\nqueue is not empty...";
}
void queue :: isfull (queue *q)
{
    (q->rear==max-1)?cout<<"\nQueue is full...":cout<<"\nqueue is not full...";
}
void queue :: insert (queue *q,int x)
{
    if (q->rear==max-1){
        cout<<"\nqueue overflows....";
    }
    else{
    ++q->rear;
    q->item[q->rear]=x;
    cout<<"\nelement is inserted....";
    }
}
int  queue :: remove (queue *q)
{
    if (q->front==q->rear){
        cout<<"\nQueue undeflows....";
        return 0;
    }
    else{
    ++q->front;
    return (q->item[q->front]);
    }
}
void queue :: display (queue *q)
{
    for (int i=q->front+1;i<=q->rear;i++)
    {
        cout<<"\t"<<q->item[i];
    }
} 
int main() 
{ 
queue *q , p,ob; 
q = &p; // Initialization of pointer
int x,z,ch; 
do {
    cout<<"\n1:create\n2:Isempty\n3:Isfull\n4:Insert\n5:Remove\n6:display\n7:Exit\nEnter the choice";
    cin>>ch;
    switch (ch)
    {
        case 1:
            ob.create (q);
            break;
        case 2:
            ob.isempty (q);
            break;
        case 3:
            ob.isfull (q);
            break;
        case 4:
            cout<<"\nEnter the element :";
            cin>>x;
            ob.insert(q,x);
            break;
        case 5:
            z=ob.remove(q);
            cout<<"\nelement is removed"<<z;
            break;
        case 6:
            ob.display (q);
            break;
        case 7:
            exit (1);
        default :
            cout<<"\nwrong input";
            break;
    }
}while (ch!=7);
return 0;
}