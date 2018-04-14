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


    static void CypeAinB(linked *a,linked *b)
    {
        if(!a->isEmpty())
        {
            Node *c;
            c=a->head;
            b->add_l(c->data);
            while(c->next!=NULL)
            {
                c=c->next;
                b->add_l(c->data);
            }
        }
        else
        {
            cout<<endl<<"list is Empty "<<endl;
        }
    }
};

int main()
{
    linked Objlist1,Objlist2;
    Objlist1.add_l(2);
    Objlist1.add_l(5);
    Objlist1.add_l(9);
    // Objlist1: 2->5->9
    linked::CypeAinB(&Objlist1,&Objlist2);
    // Objlist1: 2->5->9
    // Objlist2: 2->5->9
    return 0;
}
