#include <iostream>
#include <process.h>
using namespace std;
class node 
{
  int info;
  node *next;
  public :  //DECLARATION OF ALL OPERATION APPLIED ON SINGLY CIRCULAR L.L   
    node* create ();
    void ins_beg (int);
    void ins_end (int);
    void ins_bet (int,int);
    int rem_beg ();
    int rem_end ();
    int rem_bet (int);
    void search (int);
    void count ();
    void reverse ();
    void display ();
}*list;

node* node :: create ()//USED TO CREATE NEW NODE DYNAMICALLY
    {
        return new node;
    }

void node :: ins_beg (int x)//USED TO INSERT A NODE AT THE BEGINING OF THE SINGLY CIRCULAR L.L
    {
        node *p=list,*q;
        if (p==NULL)
            {
                p=create ();
                p->info=x;
                p->next=p;
                list=p;
            }
        else 
            {
                while (p->next!=list)
                    {
                        p=p->next;
                    }
                    q=create ();
                    q->info=x;
                    q->next=p->next;
                    p->next=q;
                    list=q;
            }
        cout<<"\nNode is Inserted :";
    }

void node :: ins_end (int x)//USED TO INSERT A NODE AT THE END OF THE SINGLY CIRCULAR L.L
    {
        node *p=list,*q;
        if (p==NULL)
            {
                p=create ();
                p->info=x;
                p->next=p;
                list=p;
            }
        else 
            {
                while (p->next!=list)
                    {
                        p=p->next;
                    }
                    q=create ();
                    q->info=x;
                    q->next=p->next;
                    p->next=q;
            }
        cout<<"\nNode is Inserted :";
    }

void node :: ins_bet (int after,int x)//USED TO INSERT A NODE IN-BETWEEN TWO NODES OF THE SINGLY CIRCULAR L.L
    {
        node *p=list,*q;
        if (p==NULL || p->next==p)
            {          
                cout<<"\nInseration between is not possible:";
            }
        else 
            {
                while (p->next!=list)
                    {
                        if (p->info==after)
                            {
                                q=create ();
                                q->info=x;
                                q->next=p->next;
                                p->next=q;
                            }
                            p=p->next;
                    }
                cout<<"\nNode is Inserted :";
            }
    }

int node :: rem_beg ()//USED TO REMOVE THE NODE WHICH IS PRESENT AT THE FIRST(BEGINING) IN SINGLY CIRCULAR L.L 
    {
        int z;
        node *p=list,*temp;
        if (p==NULL)
            {
                cout<<"\nL.L is an empty :";
            }
        else if (p->next==p)
            {
                z=p->info;
                list=NULL;
                delete (p);
                return (z);
            }
        else 
            {
                while (p->next!=list)
                    {
                        p=p->next;
                    }
                    temp=p->next;
                    z=temp->info;
                    p->next=temp->next;
                    list=temp->next;
                    delete (temp);
                    return (z);
            }
    }

int node :: rem_end ()//USED TO REMOVE THE NODE WHICH IS PRESENT AT THE LAST(END) IN SINGLY CIRCULAR L.L
    {
        int z;
        node *p=list,*temp;
        if (p==NULL)
            {         
                cout<<"\nL.L is empty :";
            }
        else if (p->next==p)
            {
                z=p->info;
                delete (p);
                list=NULL;
                return (z);
            }
        else 
            {
                while (p->next->next!=list)
                    {
                        p=p->next;
                    }
                    temp=p->next;
                    z=temp->info;
                    p->next=temp->next;
                    delete (temp);
                    return (z);
            }
    }

int node :: rem_bet (int x)//USED TO REMOVE THE NODE WHICH IS PRESENT IN-BETWEEN TWO NODES OF SINGLY CIRCULAR L.L
    {
        int z;
        node *p=list,*temp;
        if (p==NULL)
            {
                cout<<"L.L is empty :";
            }
        else if (p->next==p || p->next->next==p)
            {
                cout<<"\nRemove between is not possible :";
            }
        else 
            {
                while (p->next!=list)
                    {
                        if (p->info==x)
                            {
                                temp=p->next;
                                z=temp->info;
                                p->next=temp->next; 
                                delete (temp);
                                return (z);
                            }
                            p=p->next;
                    }
            }
    }

void node :: search (int x)//USED TO SEARCH A PARTICULAR NODE IS PRESENT OR NOT IN SINGLY CIRCULAR L.L
    {
        int t1=0;
        node *p=list;
        do
        {
            if (p->info==x)
                {
                    t1=1;
                    break;
                }   
        }while (p!=list);  
    (t1==1)?cout<<"Node is Found:":cout<<"\nNode is not Found:";      
    }

void node :: count ()//USED TO FIND HOW MANY NODES ARE PRESENT INTO GIVIN SINGILY CIRCULAR L.L        
    {
        int c=0;
        node *p=list;
        if (p==NULL)
        {
            cout<<"0";
        }
        else 
            {
                do
                {
                    c++;
                    p=p->next;
                } while (p!=list);
            cout<<"\nTotal no. of nodes :"<<c;
            }
    }

void node :: reverse ()//USED TO REVERSE THE ENTIRE L.L 
    {
        node *t1,*t2,*t3=list;
        t1=list;
        do
        {
             t2=t1->next;
             t1->next=t3;
             t3=t1;
             t1=t2;     
        } while(t1!=list);
        list=t3;
        t1->next=t3;
        cout<<"\nL.L is reversed :";
    }

void node :: display ()//USED TO DISPLAY THE CONTENT PRESENT IN GIVIN SINGLY CIRCULAR L.L
    {
        node *p=list;
        if (p==NULL)
            {
                cout<<"0";
            }
        else 
            {
            do
            {
                cout<<"\t"<<p->info;
                p=p->next;
            }while (p!=list);
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