#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedList
{
    private:
    node *head, *tail;
    public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        //node *tmp;
        // tmp = new int;
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }   
    }

    node *gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
        
    }

    static void concatenate(node *a, node *b)
    {
        if(a != NULL && b != NULL)
        {
            if(a->next == NULL)
            {
                a->next = b;
            }        
            else
            {
                concatenate(a->next, b);
            }
        }
        else
        {
            cout << "either a or b is NULL\n";
        }
        
    }
};

int main()
{
    LinkedList obj1;
    obj1.add_node(1);
    obj1.add_node(2);

    LinkedList obj2;
    obj2.add_node(3);
    obj2.add_node(4);

    LinkedList::concatenate(a.gethead(), b.gethead());
    LinkedList::display(a.gethead());

    return 0;
}