#include <iostream>
using namespace std;
#include <process.h>
#define  max   5
class queue
{
    int item[max],rear,front;
    public :
        void create (queue *);
        void isempty (queue *);
        void isfull (queue *);
        void insert (queue *,int);
        int remove (queue *);
        void display (queue *);
};
void queue :: create (queue *p)
{
    p->front=p->rear=-1;
    cout<<"\n queue is created .....";
}
void queue :: isempty (queue *p)
{
    (p->front==-1)?cout<<"\nqueue is empty":cout<<"\nqueue is not empty";
}
void queue :: isfull (queue *p)
{
    ((p->front==0 && p->rear==max-1)||(p->front==p->rear+1))?cout<<"\nqueue is full":cout <<"\n queue is not full";
}
void queue :: insert (queue *p,int x)
{
    if ((p->front==0 && p->rear==max-1)||(p->front==p->rear+1)) {
        cout<<"\nqueue overflows....";
    }
    else{
         if ( p->front == -1) 
            { 
                p->front = p->rear = 0;
            } 
        else 
            { 
                p->rear = (p->rear + 1) % max ; //increments ‘rear’ circularly. 
            } 
            p->item[p->rear] = x ;
            cout<<"Element is inserted…."<<x;
    }
}
int queue :: remove  (queue *p)
{
    int z;
    if (p->front==-1){
        cout<<"\nqueue underflows...";
    }
    else{
         z = p->item[p->front]; 
            if ( p->front == p->rear) 
                { 
                    p->front = p->rear = -1 ; 
                } 
            else 
                { 
                    p->front = (p->front + 1) % max ; //increments ‘front’ circularly.
                } 
               return(z) ;
    }
}
void queue :: display (queue *p)
{
    for (int i=p->front;i!=p->rear;i=(i+1)%max){
        cout<<"\t"<<p->item[i]; //display the ele.
    }
    cout<<"\t"<<p->item[p->rear]; //
}
int main ()
{
    queue *p,q,ob;
    p=&q;
    int ch,x,z;
    do {
    cout<<"\n1:create\n2:Isempty\n3:Isfull\n4:Insert\n5:Remove\n6:display\n7:Exit\nEnter the choice";
    cin>>ch;
    switch (ch)
    {
        case 1:
            ob.create (p);
            break;
        case 2:
            ob.isempty (p);
            break;
        case 3:
            ob.isfull (p);
            break;
        case 4:
            cout<<"\nEnter the element :";
            cin>>x;
            ob.insert(p,x);
            break;
        case 5:
            z=ob.remove(p);
            cout<<"\nelement is removed"<<z;
            break;
        case 6:
            ob.display (p);
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