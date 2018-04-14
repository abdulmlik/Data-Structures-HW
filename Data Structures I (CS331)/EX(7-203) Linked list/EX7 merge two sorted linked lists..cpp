#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


using namespace std;

struct node
{
    int data;
    struct node* next;
};

void MoveNode(struct node** destRef, struct node** sourceRef);

struct node* SortedMerge(struct node* a, struct node* b)
{
    struct node dummy;

    struct node* tail = &dummy;

    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {

            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return(dummy.next);
}


/*
   Before calling MoveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}

   Affter calling MoveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3} */
void MoveNode(struct node** destRef, struct node** sourceRef)
{
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;

    newNode->next = *destRef;

    *destRef = newNode;
}


void push(struct node** head_ref, int new_data)
{
    struct node* new_node =new node;

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


void printList(struct node *node)
{
    cout<<"node";
    while (node!=NULL)
    {
        cout<<"->"<<node->data;
        node = node->next;
    }
}


int main()
{

    struct node* Objlist3 = NULL;
    struct node* Objlist1 = NULL;
    struct node* Objlist2 = NULL;

    push(&Objlist1, 15);
    push(&Objlist1, 10);
    push(&Objlist1, 5);

    push(&Objlist2, 20);
    push(&Objlist2, 3);
    push(&Objlist2, 2);

    Objlist3 = SortedMerge(Objlist1, Objlist2);

    cout<<"Merged Linked List is: \n";
    printList(Objlist3);

    return 0;
}
