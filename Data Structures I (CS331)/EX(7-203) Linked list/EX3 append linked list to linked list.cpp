#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    node *next;
};

void areIdentical(node *a, node *b)
{
    while (1)
    {

        a = a->next;
        if(a->next==NULL)
        {
          a->next=b;
          break;
        }

    }

    return ;
}


void push(struct node** head_ref, int new_data)
{

    node* new_node = new node;

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


int main()
{
    /*
     Objlist1: 3->2->1
     Objlist2: 3->2->1
    */
    node *Objlist1 = NULL;
    node *Objlist2 = NULL;
    push(&Objlist1, 1);
    push(&Objlist1, 2);
    push(&Objlist1, 3);
    push(&Objlist2, 1);
    push(&Objlist2, 2);
    push(&Objlist2, 3);

    areIdentical(Objlist1, Objlist2);
    /*
     Objlist1: 3->2->1->b:3->2->1
    */

    return 0;
}
