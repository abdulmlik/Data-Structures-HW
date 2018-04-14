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


    void reverse()
    {
        Node *p,*c,*temp;
        c=head;
        head=tail;
        tail=c;
        //////////////
        p=temp=c;
        p=c=c->next;
        c=c->next;
        p->next=temp;
        temp=p;
        p=c;
        while(1)
        {

            c=c->next;
            p->next=temp;
            temp=p;
            p=c;
            if(c->next==NULL)
            {
                c->next=temp;
                break;
            }
        }

    }
};

int main()
{
    linked Objlist1;
    Objlist1.add_l(1);
    Objlist1.add_l(2);
    Objlist1.add_l(3);
    Objlist1.add_l(4);
    // L: 1->2->3->4
    Objlist1.reverse();
    // L: 4->3->2->1
    return 0;
}
