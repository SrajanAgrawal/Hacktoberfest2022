#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print_list(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *insertatbegin(Node *head, int data)
{

    Node *newnode = new Node();

    newnode->next = head;
    head = newnode;
    newnode->data = data;

    return head;
}

Node *inseratpost(Node *head, int post, int data)
{

    Node *temp = head;
    Node *newnode = new Node();
    int i;

    for (i = 1; i < post - 1; i++)
    {

        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->data = data;

    return head;
}

Node *insertatlast(Node *head, int data)
{

    Node *temp = head;
    Node *newnode = new Node();

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->data = data;
    newnode->next = NULL;

    return head;
}

Node *reverse_ll(Node *head)
{
    Node *current = head;
    Node *forward = NULL;
    Node *prev = NULL;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node *delatbegin(Node *head)
{

    Node *temp = head;

    head = head->next;
    free(temp);

    return head;
}

Node *delatlast(Node *head)
{

    Node *forward = head->next;
    Node *current = head;

    while (forward->next != NULL)
    {
        current = current->next;
        forward = forward->next;
    }

    current->next = NULL;
    free(forward);

    return head;
}

Node *delatpost(Node *head, int post)
{

    Node *forward = head->next;
    Node *current = head;
    int i;
    for (i = 1; i < post - 1; i++)
    {
        current = current->next;
        forward = forward->next;
    }

    current->next = forward->next;
    free(forward);

    return head;
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    //  head = insertatlast(head , 45);
    head = reverse_ll(head);

    // head = delatbegin(head);
    // head = delatlast(head);
    //  head =  delatpost(head , 2);

    print_list(head);
    return 0;
}