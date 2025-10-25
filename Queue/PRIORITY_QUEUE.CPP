#include <iostream>
using namespace std;
#define  max  5
#include <process.h>
class queue
{
    int item[max],priority[max],rear,front;
    public :
        void create (queue *);
        void insert (queue *,int,int);
        int remove (queue *);
        void display (queue *);
};
void queue :: create (queue *q)
{
    q->front=q->rear=-1;
    cout<<"\nQueue is created :";
}
void queue :: insert (queue *q,int x,int pr)
{
    if (q->rear==max-1){
        cout<<"\nqueue overflows:";
    }   
    else{
        ++q->rear;
        q->item[q->rear]=x;
        q->priority[q->rear]=pr;
        cout<<"\nElement is inserted:";
    }
}
int queue :: remove (queue *q)
{
    int m,pos=0,i,z;
    if (q->front==q->rear){
        cout<<"\nQueue underflows :";
        return (0);
    }
    else{
        m=q->priority[0];  //logic of finding the greatest no. from array
        for (i=q->front+1;i<=q->rear;i++){
             if (m<q->priority[i]){
                    m=q->priority[i];
                    pos=i;
             }
        }
        z=q->item[pos]; //taking the positon in z i.e actually we can retrive the element from queue. 
        for (i=pos;i<=q->rear;i++){  //after removing the ele. shift the places of ele. and their respective priority. 
                q->item[i]=q->item[i+1];
                q->priority[i]=q->priority[i+1];
        }
        --q->rear; //decrement the rear becuse now it will be point at that point.
        return (z);
    }
}
void queue :: display (queue *q)
{
   cout<<"\nPriority of an queue :";
   for (int i=q->front+1;i<=q->rear;i++){
        cout<<"\t"<<q->priority[i];
   }
    cout<<"\nElements of an queue :";
   for (int i=q->front+1;i<=q->rear;i++){
        cout<<"\t"<<q->item[i];
   }   
}
int main ()
{
    int ch,x,pr,z;
    queue ob;
    queue *q,p;
    q=&p;
    do{
        cout<<"\n1:Create\n2:Insert\n3:Remove\n4:Display\n5:Exit\nEnter the choice:";
        cin>>ch;
        switch (ch)
            {
                case 1:
                    ob.create(q);
                    break;
                case 2:
                    cout<<"\nEnter the Element :";
                    cin>>x;
                    cout<<"\nEnter the Priority :";
                    cin>>pr;
                    ob.insert(q,x,pr);
                    break;
                case 3:
                    z=ob.remove(q);
                    cout<<"\nElement is Removed:"<<z;
                    break;
                case 4:
                    ob.display (q);
                    break;
                case 5:
                    exit (1);
                default :
                    cout<<"\nwrong input:";
                    break;
            }
    }while (ch!=5);
return 0;
}