#include <iostream>
using namespace std;
#define size 5
string Queue[size];
int front, rear, i;
string x;

void init()
{
    front = rear = -1;
}

void enqueue(string data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;

        Queue[rear] = data;
    }
    else if ((rear + 1) % size == front)
    {
        cout << "\nQueue is Full";
    }
    else
    {
        rear = (rear + 1) % size;
        Queue[rear] = data;
    }
}

void print()
{
    i = front;
    while (i != rear)
    {
        cout << Queue[i] << " ";
        i = (i + 1) % size;
    }

    cout << Queue[rear];
}

string dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "\n Empty";
    }
    else if (front == rear)
    {
        x = Queue[front];
        front = rear = -1;
    }
    else
    {
        x = Queue[front];
        front = (front + 1) % size;
    }

    return x;
}
int main()
{
    init();
    enqueue("Shahin");
    enqueue("Asik");
    enqueue("Tanzim");
    enqueue("Nasif");
    enqueue("Tamanna");
    print();
    cout << endl;
    cout << dequeue();
    cout << endl;
    cout << dequeue();

    print();
    cout << endl;
    enqueue("Kaberi");
    cout << endl;
    print();

    return 0;
}
