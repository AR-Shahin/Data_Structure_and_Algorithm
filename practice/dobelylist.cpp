#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *head, *temp;
int count = 0;
void initial()
{
    head = NULL;
}
void insert(int val)
{
    node *newNode;
    newNode = new node;

    newNode->data = val;
    newNode->next = newNode->prev = NULL;

    if (head == NULL)
    {
        temp = head = newNode;
    }
    else
    {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    count++;
}
void display()
{
    cout << "\nDisplay Data : ";
    node *t;
    t = head;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

void reversePrint()
{
    node *t;
    t = temp;
    cout << "\nDisplay Data : ";
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->prev;
    }
}

int pop()
{
    cout << endl;
    node *t = temp;
    int data = temp->data;
    cout << endl;
    cout << "\nprev : " << t->prev->data << endl;
    temp = temp->prev;
    free(t);
    return data;
}
void insertFirst(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
    count++;
}
int lengthOfList()
{
    return count;
}
void insertAtPosition(int pos, int data)
{
    if (pos == 1)
    {
        insertFirst(data);
        return;
    }
    else
    {
        int i = 1;
        node *t, *newNode;
        t = head;
        while (i < pos - 1)
        {
            t = t->next;
            i++;
        }
        newNode = new node;

        newNode->prev = t;
        newNode->next = t->next;
        newNode->data = data;

        t->next = newNode;
        newNode->next->prev = newNode;
        count++;
    }
}
int deleteFirst()
{
    cout << endl;
    node *t;
    t = head;
    int data = t->data;
    head = head->next;
    head->prev = NULL;
    free(t);
    count--;
    return data;
}
int deleteLast()
{
    cout << endl;
    node *t;
    t = temp;

    int data = temp->data;
    temp = temp->prev;
    temp->next = NULL;
    free(t);
    count--;
    return data;
}
void deletePosition(int pos)
{

    node *t = head;
    if (pos > lengthOfList())
    {
        cout << "Invaid!" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
    }
    if (pos == lengthOfList())
    {
        deleteLast();
    }

    int index = 1;

    while (index != pos)
    {
        t = t->next;
        index++;
    }

    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}
int main()
{
    initial();
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    display();
    deletePosition(5);

    display();
    return 0;
}
