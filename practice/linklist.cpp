#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *head;

void insertFirst(int val)
{
    node *newNode;
    newNode = new node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void insertLast(int val)
{
    if (head == NULL)
    {
        insertFirst(val);
    }
    else
    {
        node *newNode;
        newNode = new node;
        newNode->data = val;
        newNode->next = 0;
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
void insertDobelyFirst(int val)
{
    node *newNode;
    newNode = new node;
    newNode->data = val;
    if (head == NULL)
    {
        newNode->prev = NULL;
    }

    newNode->next = head;
    head = newNode;
}
void initial()
{
    head = NULL;
}

void display()
{
    cout << "\nDisplay Data : ";
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    initial();
    insertLast(10);
    insertLast(20);
    insertLast(30);
    display();
    return 0;
}
