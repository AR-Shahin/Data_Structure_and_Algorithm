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
int lengthOfList()
{
    return count;
}
void enqueue(int data)
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
int dequeue()
{
    if (head == NULL)
    {
        cout << "\nEmpty List" << endl;
        return -0;
    }
    else
    {
        node *temp = head;
        int data = temp->data;
        head = head->next;

        free(temp);
        return data;
    }
}

int main()
{
    initial();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    cout << endl;
    cout << dequeue();
    display();
    enqueue(50);
    display();
    cout << endl;
    cout << dequeue();
    display();
    return 0;
}
