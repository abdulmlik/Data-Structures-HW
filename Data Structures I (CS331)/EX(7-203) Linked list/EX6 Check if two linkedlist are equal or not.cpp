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

    static int Com(linked *a,linked *b)
    {
        if(!a->isEmpty()&&!b->isEmpty())
        {
            Node *c,*o;
            int m=1;
            c=a->head;
            o=b->head;
            if(c->data!=o->data){m=0;}
            while(c->next!=NULL)
            {
                c=c->next;
                if(c->data!=o->data){m=0;}
            }
            return m;//(m)? cout<<"\nis Equal\n" : cout<<"\nis not Equal\n";
        }
        else
        {
            cout<<endl<<"list A or B is Empty "<<endl;
            return 0;
        }
    }
};

int main()
{
    linked Objlist1,Objlist2;
    Objlist1.add_l(6);
    Objlist1.add_l(1);
    Objlist1.add_l(7);

    Objlist2.add_l(6);
    Objlist2.add_l(1);
    Objlist2.add_l(7);
    ((linked::Com(&Objlist1,&Objlist2)))? cout<<"\nis Equal\n" : cout<<"\nis not Equal\n";
    return 0;
}
