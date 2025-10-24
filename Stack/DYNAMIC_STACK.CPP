#include <iostream>
#include <process.h>
using namespace std;
class node
    {
        int info;
        node *next;
        public:
            node* create ();
            void isempty();
            void push (int);
            int pop();
            void display ();
    }*list;
node* node :: create ()
    {
        return new node;
    }
void node :: isempty ()
    {
        node *p=list;
        (p==NULL)?cout<<"\nSTACK is empty:":cout<<"\nSTACK is not an empty:";
    }
void node :: push (int x) //INS_BEG
    {
        node *p=list,*q;
        if (p==NULL){
            p=create ();
            p->info=x;
            p->next=NULL;
            list=p;
        }else{
            q=create ();
            q->info=x;
            q->next=p;
            list=q;
        }
        cout<<"\nNODE is inserted :";
    }
int node :: pop() //REM_BEG
    {
        int z;
        node *p=list;
        if (p==NULL)
            {
                cout<<"\nSTACK undeflow:";
            }
        else if (p->next==NULL)
            {
                z=p->info;
                list=NULL;
                delete (p);
                return (z);
            }
        else
            {
                z=p->info;
                list=p->next;
                delete (p);
                return (z);
            }
    }
void node :: display ()
    {
        node *p=list;
        while (p!=NULL)
            {
                cout<<"\n"<<p->info;
                p=p->next;
            }
    }
int main ()
    {
        node ob;
        int x,z,ch;
        do{
        cout<<"\n1:ISEMPTY\n2:PUSH\n3:POP\n4:DISPLAY\n5:EXIT\nEnter the choice:";
        cin>>ch;
        switch (ch)
            {
                case 1:
                    ob.isempty();
                    break;
                case 2:
                    cout<<"\nEnter the element:";
                    cin>>x;
                    ob.push (x);
                    break;
                case 3:
                    z=ob.pop();
                    cout<<"\nRemoved value is:"<<z;
                    break;
                case 4:
                    ob.display();
                    break;
                case 5:
                    exit (1);
                default :
                    cout<<"\nWrong choice:";
                    break;
            }
        }while (ch!=5);
        return (0);
    }