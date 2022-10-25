#include <iostream>
using namespace std;
struct node
{
   node *next;
   node *prev;
   int data;
   node(int d)
   {
       // next = NULL;
       // prev = NULL;
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
   node *get_next_node(node *head, int i)
   {
       if (i != 1)
           i += i;

       node *temp = head;
       for (int k = 0; k <= i && temp->next != NULL; k++)
           temp = temp->next;
       return temp;
   }
   node *get_prev_node(node *head, int i)
   {
       node *temp = head;
       if (i != 0)
           i += i;
       for (int k = 0; k <= i && temp->prev != NULL; k++)
           temp = temp->prev;
       return temp;
   }
   void search(node *head, int key)
   {
       if (head == NULL)
       {
           insertAtHead();
           insertAtTail();
       }
       static int i = 0;
       static bool flag = false;
       cout << head->data << "  ";
       if (key == head->data)
       {
           cout << "\n"<<key<<" key found\n";
           flag = true;
           return;
       }
       else if (i != 0)
           return;
       for (int k = 0; k >= 0; k++)
       {
           if (flag == true)
               return ;
           ++i;
           head = get_next_node(head, i);
           insertAtHead();
           search(head, key);
           if(!flag) {
               head = get_prev_node(head, i);
               insertAtTail();
               search(head, key);
           }
       }
   }
  void search_f(int key)
   {
       search(head, key);
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
