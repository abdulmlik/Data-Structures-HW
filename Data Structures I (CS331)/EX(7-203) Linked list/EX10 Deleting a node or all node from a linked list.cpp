#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linked
{
    Node *head,*tail;
public:
    linked()
    {
        head=tail=NULL;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void add_l(int item)
    {
        Node *n=new Node;
        n->data=item;
        n->next=NULL;
        if(isEmpty())
        {
            head=tail=n;
        }
        else
        {
            tail->next=n;
            tail=n;
        }
    }
    void delete_x(int x)
    {
        if(!isEmpty())
        {
            Node *p;
            if(head->data==x)
            {
                p=head;
                head=head->next;
                p->next=NULL;
                delete p;
            }
            else
            {
               Node *c=head;
               while(c->next!=NULL)
               {
                   if(c->next->data==x)
                   {
                       p=c->next;
                       c->next=p->next;
                       p->next=NULL;
                       break;
                   }
                   else
                   {
                       c=c->next;
                   }
               }
               if(c->next==NULL){cout<<endl<<x<<" not found"<<endl;}
            }

        }
        else
            cout<<endl<<"list is Empty "<<endl;
    }

    void delete_ALL()
    {
        if(!isEmpty())
        {
            Node *p;
            p=head;
            tail=NULL;
            head=NULL;
            delete p; //delete p->next ...
        }
        else
            cout<<endl<<"list is Empty "<<endl;
    }
};

int main()
{
    linked Objlist1;
    Objlist1.add_l(6);
    Objlist1.add_l(1);
    Objlist1.add_l(7);
    Objlist1.delete_ALL();
    return 0;
}
