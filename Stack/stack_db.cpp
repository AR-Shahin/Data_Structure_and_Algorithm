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
void push(int data)
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
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
int pop()
{
    if (head == NULL)
    {
        cout << "\nEmpty List" << endl;
    }
    else
    {
        node *temp = tail;
        int data = temp->data;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        return data;
    }
}
int main()
{
    initial();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();
    return 0;
}
