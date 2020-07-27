/* LINKED LIST */

// we achive make a node in C with structures and pointer
// Each structures represents a node having some data and also
// pointer to another structure of the same kind.
// The pointer holds the address of next node and creates link between two nodes


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // hold address of next node as "*next"
};


void display(struct node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head->data);
        display(head->next);
    }
    
}

// NOTE
//if we access to the first node then we access any node of the linked list.
// the accessing is "a->next" (the pointer storing the address of the next node is named "next".

int main()
{
    struct node *prev, *head, *p; // we made a three nodes
    int n, i;
    printf ("number of elements:");
    scanf("%d", &n);
    head = NULL;
    for (i=0; i<n; i++)
    {
        //creating node 'p'
        p = malloc(sizeof(struct node)); // allocating the space required for a node
        scanf("%d", &p->data); // &p is the address of pointer (referencing)
        p->next = NULL; // node p compledted, initialization

        if (head == NULL) // if the head is NULL, then our linked list is not created
        {
            head = p;
        }
        else
        {
            prev->next=p; // for next iteration, current iteration is previous.
            prev = p;  //We made last node as a prev for next iteration
        }
    }
    display(head);    
    return 0;
}





