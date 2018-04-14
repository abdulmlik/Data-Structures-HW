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
    int num()
    {
        if(!isEmpty())
        {
            int i=1;
            Node *c;
            c=head;
            while(c->next!=NULL)
            {
                i++;
                c=c->next;
            }
            return i;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    linked *Objlist1;
    Objlist1->add_l(6);
    Objlist1->add_l(1);
    Objlist1->add_l(7);
    int i=Objlist1->num();
    (i>0)? cout<<"Long List = "<<i<<endl : cout<<endl<<"list is Empty "<<endl;
    return 0;
}
