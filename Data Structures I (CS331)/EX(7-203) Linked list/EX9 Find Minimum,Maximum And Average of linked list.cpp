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
    void max_min_avg()
    {
        if(!isEmpty())
        {
            int sum=0,i=1,max,min;
            float avg;
            Node *c;
            c=head;
            max=min=c->data;
            sum+=c->data;
            while(c->next!=NULL)
            {
                i++;
                c=c->next;
                sum+=c->data;
                if(c->data>max){max=c->data;}
                if(c->data<min){min=c->data;}
            }
            avg=sum/i;
            cout<<endl<<"Max = "<<max<<"  Min = "<<min<<"  Avg = "<<avg<<endl;
        }
        else
        {
            cout<<endl<<"list is Empty "<<endl;
        }
    }
};

int main()
{
    linked Objlist1;
    Objlist1.add_l(6);
    Objlist1.add_l(1);
    Objlist1.add_l(7);
    Objlist1.max_min_avg();
    return 0;
}
