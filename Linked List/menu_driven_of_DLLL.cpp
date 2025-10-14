#include <iostream>
using namespace std;
#include <process.h>
class node 
{
    int info;    
    node *next,*prev;
    public :  //DECLARATION OF ALL OPERATION APPLIED ON DOUBLY LINEAR L.L
        node* create ();
        void ins_beg (int);
        void ins_end (int);
        void ins_bet (int,int);
        int rem_beg ();
        int rem_end ();
        int rem_bet(int);
        void search (int);
        void count ();
        void reverse ();
        void display ();

}*list;

node* node :: create()//USED TO CREATE NEW NODE DYNAMICALLY
    {
        return new node;
    }

void node :: ins_beg (int x)//USED TO INSERT A NODE AT THE BEGINING OF THE DOUBLY LINEAR L.L
    {
        node *p,*q;
        p=list;
        if (p==NULL)
            {
                p=create ();
                p->info=x;
                p->prev=NULL;
                p->next=NULL;
                list=p;
            }
        else 
            {
                q=create ();
                q->info=x;
                q->prev=NULL;
                q->next=p;
                p->prev=q;
                list=q;
            }
            cout<<"\nNode is inserted :";
    }

void node :: ins_end (int x)//USED TO INSERT A NODE AT THE END OF THE DOUBLY LINEAR L.L
    {
        node *p,*q;
        p=list;
        if (p==NULL)
            {
                p=create ();
                p->info=x;
                p->prev=NULL;
                p->next=NULL;
                list=p;
            }
        else
            {
                while (p->next!=NULL)
                    {
                        p=p->next;
                    }
                    q=create ();
                    q->info=x;
                    q->prev=p;
                    q->next=NULL;
                    p->next=q;
            }
            cout<<"\nNode is inserted :";
    }

void node :: ins_bet (int after,int x)//USED TO INSERT A NODE IN-BETWEEN TWO NODES OF THE DOUBLY LINEAR L.L
    {
        node *p,*q;
        p=list;
        if (p==NULL || p->next==NULL)
            {
                cout<<"\ninsert between is not possible :";
            }
        else    {
            while (p->next!=NULL)
                {
                    if (p->info==after)
                        {
                            q=create ();
                            q->info=x;
                            q->prev=p;
                            q->next=p->next;
                            p->next->prev=q;
                            p->next=q;
                        }
                        p=p->next;
                }
        }
        cout<<"\nNode is inserted :";
    }

int node :: rem_beg ()//USED TO REMOVE THE NODE WHICH IS PRESENT AT THE FIRST(BEGINING) IN DOUBLY LINEAR L.L
{
   int z;
     node *p;
     p=list;
     if (p==NULL)
        {
            cout<<"L.L is empty :";
        }
    else if (p->prev==NULL && p->next==NULL)
        {
            z=p->info;
            list=NULL;
            delete (p);
            return (z);
        }
    else 
        {
            z=p->info;
            p->next->prev=NULL;
            list=p->next;
            delete (p);
            return(z);
        }
}

int node :: rem_end ()//USED TO REMOVE THE NODE WHICH IS PRESENT AT THE LAST(END) IN DOUBLY LINEAR L.L
    {
        int z;
        node *p,*temp;
        p=list;
        if (p==NULL)
            {
                cout <<"\nL.L is empty :";
            }
        else if (p->next==NULL && p->prev==NULL)
            {
                z=p->info;
                list=NULL;
                delete (p);
                return (z);
            }
        else 
            {
                while (p->next->next!=NULL)
                    {
                        p=p->next;
                    }
                    temp=p->next;
                    z=temp->info;
                    p->next=NULL;
                    delete (temp);
                    return (z);
            }
    }

int node :: rem_bet (int after)//USED TO REMOVE THE NODE WHICH IS PRESENT IN-BETWEEN TWO NODES OF DOUBLY LINEAR L.L
    {
        int z;
        node *p,*temp;
        p=list;
        if (p==NULL)
            {
                cout<<"L.L is empty :";
            }
        else if ((p->next==NULL && p->prev==NULL) || (p->next->prev==NULL && p->next->next==NULL))
            {
                cout<<"\nremove operation cannot happens :";
            }
        else 
            {
                while (p->next!=NULL)
                    {
                        if (p->info==after)
                            {
                                temp=p->next; 
                                z=temp->info;
                                temp->next->prev=p;
                                p->next=temp->next;
                                return (z);
                                delete (temp);
                            }
                        p=p->next;
                    }
            }
    }

void node ::search (int x)//USED TO SEARCH A PARTICULAR NODE IS PRESENT OR NOT IN DOUBLY LINEAR L.L
    {
        node *p;
        int t=0;
        p=list;
        while (p!=NULL)
            {
                if (p->info==x)
                    {
                        t=1;
                        break;
                    }
                    p=p->next;
            }
            (t==1)?cout<<"\nNode is Found :":cout<<"\nNode is not Found :";
    }

void node :: count ()//USED TO FIND HOW MANY NODES ARE PRESENT INTO GIVIN DOUBLY LINEAR L.L
    {
        node *p;
        int c=0;
        p=list;
        while (p!=NULL)
            {
                c++;
                p=p->next;
            }
        cout<<"\nTotal no. of nodes are :"<<c;
    }

void node :: reverse ()//USED TO REVERSE THE ENTIRE L.L
    {
        node *t1,*t2,*t3=NULL;
        t1=list;
        while (t1!=NULL)
            {
                t2=t1->next;
                t1->next=t3;
                t1->prev=t2;
                t3=t1;
                t1=t2;
            }
        list=t3;
        cout<<"\nL.L is Reversed :";
    }

void node :: display ()//USED TO DISPLAY THE CONTENT PRESENT IN GIVIN DOUBLY LINEAR L.L
    {
        node *p,*q;
        p=list;
        while (p!=NULL)
            {
                cout<<"\t"<<p->info;
                p=p->next;
            }
    }

int main ()
    {
        int ch,af,x,z,n,n1;
        node ob;
        do
        {
            cout<<"\n1:insert at First\n2:insert at end\n3:insert at between\n4:Remove from First\n5:Remove from End\n6:Remove from between\n7:Search\n8:Count\n9:Reverse\n10:Display\n11:Exit\nEnter the choice :";
            cin>>ch;
            switch (ch)
                {
                    case 1:
                        cout<<"\nEnter the node :";
                        cin>>x;
                        ob.ins_beg(x);
                        break;

                    case 2:
                        cout<<"\nEnter the node :";
                        cin>>x;
                        ob.ins_end(x);
                        break;

                    case 3:
                        cout<<"\nafter which node :";
                        cin>>af;
                        cout<<"\nEnter the node :";
                        cin>>x;
                        ob.ins_bet(af,x);
                        break;

                    case 4:
                        z=ob.rem_beg ();
                        cout<<"\nNode is removed :"<<z;
                        break;

                    case 5:
                        z=ob.rem_end ();
                        cout<<"\nNode is removed :"<<z;
                        break;

                    case 6:
                        cout<<"\nafter which node :";
                        cin>>n;
                        z=ob.rem_bet (n);
                        cout<<"\nNode is removed :"<<z;
                        break;

                    case 7:
                        cout<<"\nEnter the value for searching :";
                        cin>>n1;
                        ob.search (n1);
                        break;

                    case 8:
                        ob.count ();
                        break;
                    
                    case 9:
                        ob.reverse();
                        break;

                    case 10:
                       ob.display();
                        break;


                    case 11:
                        exit (1);

                    default :
                        cout<<"\nwrong input :";
                }
        } while (ch!=11);
        
        return 0;
    }