#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head, *tail;
int count = 0;
void initial()
{
    head = NULL;
}
void insertFirst(int data)
{
    node *newNode;
    newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;
}
void insertLast(int data)
{
    if (head == NULL)
    {
        insertFirst(data);
        return;
    }
    else
    {
        node *newNode;
        newNode = new node;
        newNode->data = data;
        tail->next = newNode;
        newNode->next = NULL;
        newNode->prev = tail;
        tail = newNode;
        count++;
    }
}
int lengthOfList()
{
    return count;
}
void insertAtPosition(int pos, int data)
{
    if (pos > lengthOfList())
    {
        cout << "\nInvalid Postion" << endl;
        return;
    }
    if (pos == 1)
    {
        insertFirst(data);
        return;
    }

    if (pos == lengthOfList())
    {
        insertLast(data);
        return;
    }

    int index = 1;
    node *temp = head;
    while (index < pos - 1)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        index++;
    }
    node *newNode;
    newNode = new node;
    newNode->data = data;

    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    count++;
}
void display()
{
    cout << "\nDisplay : ";
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverseDisplay()
{
    if (tail == head)
    {
        display();
        return;
    }
    cout << "\nDisplay : ";
    node *temp;
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
int main()
{
    initial();
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    // // insertFirst(50);
    // insertLast(10);
    // insertLast(50);
    // insertLast(60);
    // insertFirst(200);
    // reverseDisplay();
    display();
    reverseDisplay();
    cout << endl;
    insertAtPosition(3, 500);
    insertAtPosition(3, 5200);

    insertAtPosition(4, 1000);
    display();
    reverseDisplay();

    return 0;
}
