#include <iostream>
// #include <stdlib>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;
int count = 0;

void init()
{
    head = 0;
}

void insertFirst(int data)
{
    Node *newNode;

    newNode = new Node;

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    count++;
}

int lengthOfList()
{
    return count;
}
void display()
{
    if (head == 0)
    {
        cout << "Empty";
    }
    else
    {
        Node *temp;
        temp = head;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void insertLast(int data)
{
    if (head == 0)
    {
        insertFirst(data);
    }
    else
    {
        Node *newNode, *temp;

        newNode = new Node;

        newNode->data = data;
        newNode->next = 0;
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        count++;
    }
}

void insertAfterPosition(int pos, int data)
{
    int index = 1;
    if (pos == 0)
    {
        cout << "Zero Can't Allowed!!";
    }
    if (pos == 1)
    {
        insertFirst(data);
    }
    if (lengthOfList() < pos)
    {
        cout << "Invalid Position!!";
    }
    else
    {
        Node *temp, *newNode;
        temp = head;
        while (index < pos - 1)
        {
            temp = temp->next;
            index++;
        }

        newNode = new Node;

        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }
}

void deleteFirst()
{
    if (head == 0)
    {
        cout << "Empty";
    }
    else
    {
        Node *temp;

        temp = head;

        head = head->next;

        free(temp);
    }
}
void deleteLast()
{
    if (head == 0)
    {
        cout << "Empty";
    }
    else
    {
        Node *temp, *prev;
        temp = head;

        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        if (head == temp)
        {
            head = 0;
        }
        else
        {
            prev->next = 0;
        }
        free(temp);
    }
}

Node *returnNodeByValue(int val)
{
    Node *temp;

    temp = head;

    while (temp->next != 0)
    {
        if (temp->data == val)
        {
            return temp;
        }

        temp = temp->next;
    }

    return temp;
}

void updateValue(int old, int newVal)
{
    Node *oldNode;
    oldNode = returnNodeByValue(old);
    oldNode->data = newVal;
}

int getMaxValue()
{
    int max = INT_MIN;

    Node *temp;
    temp = head;

    while (temp->next != 0)
    {
        if (max < temp->data)
        {
            max = temp->data;
        }

        temp = temp->next;
    }

    return max;
}

int getMinValue()
{
    int min = INT_MAX;

    Node *temp;
    temp = head;

    while (temp->next != 0)
    {
        if (min > temp->data)
        {
            min = temp->data;
        }

        temp = temp->next;
    }

    return min;
}
int main()
{
    init();
    insertFirst(1000);
    insertFirst(200);
    insertFirst(300);
    insertFirst(5);
    insertLast(400);
    insertFirst(100);
    // cout << lengthOfList();
    display();
    // insertAfterPosition(2, 500);
    // insertAfterPosition(3, 1000);
    // deleteFirst();
    cout << "\n";
    // deleteLast();
    // cout << "\n";
    // display();

    // Node *t;
    // t = returnNodeByValue(300);
    // cout << t->data;
    // updateValue(200, 2000);
    // cout << "\n";
    // display();
    cout << getMaxValue();
    cout << "\n";
    cout << getMinValue();
    return 0;
}
