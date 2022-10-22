#include <iostream>
using namespace std;
struct node
{
    node *next;
    node *prev;
    int data;
    node(int d)
    {
        data = d;
    }
};
class linklist
{
public:
    node *head;
    node *tail;
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtTail()
    {
        int data = rand() % 10000;
        if (head == NULL)
        {
            insertAtHead();
            return;
        }
        node *n_node = new node(data);
        node *temp = head;
        tail->next = n_node;
        n_node->prev = tail;
        tail = n_node;
    }
    void insertAtHead()
    {
        int data = rand() % 10000;
        node *n_node = new node(data);
        if (head == NULL)
        {
            head = n_node;
            tail = head;
            n_node->next = head;
            return;
        }
        n_node->next = head;
        head->prev = n_node;
        head = n_node;
    }

    void search(node *head, node *head1, int key)
    {
        cout << head->data << "  " << head1->data << "  ";
        if (key == head->data || key == head1->data)
        {
            cout << "\n"
                 << key << " key found\n";
            return;
        }
        insertAtHead();
        insertAtTail();
        search(head->next, head1->prev, key);
    }
    void search_f(int key)
    {
        node *temp = head;
        search(head, temp, key);
    }
};
int main()
{
    srand(time(0));
    linklist *l = new linklist;
    l->insertAtTail();
    l->insertAtHead();
    l->search_f(50);
    delete l;
    return 0;
}
