#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next; // "next" is next node.
};

class LinkedList
{
    private:
    node *head, *tail; // tail is last node. head is first node and reference for traversal.
    public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    
    // CREATE a FUNCTION of ADDING a NODE TO OUR LINKED LIST
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
    
    // TRAVERSAL USING RECURSION
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
    
    // CONCATENATE a NODE and b NODE
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

    LinkedList::concatenate(obj1.gethead(), obj2.gethead());
    LinkedList::display(obj1.gethead());

    return 0;
}
