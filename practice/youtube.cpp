#include <iostream>
using namespace std;
#define size 5
string Queue[size];
int front, rear;

void init()
{
    front = rear = 0;
}

void enqueue(string data)
{
    if (rear < size)
    {
        Queue[rear] = data;
        rear++;
    }
    else
    {
        cout << "Queue is Full!\n";
    }
}

void print()
{
    for (int i = front; i < rear; i++)
    {
        cout << Queue[i] << " ";
    }
}
string dequeue()
{
    string data = Queue[front];
    front++;
    return data;
}
int main()
{
    init();
    enqueue("Shahin");
    enqueue("Asik");
    enqueue("Tanzim");
    enqueue("Nasif");
    enqueue("Tamanna");
    enqueue("Kaberi");
    print();
    cout << endl;
    cout << dequeue();
    cout << endl;
    cout << dequeue();
    cout << endl;

    print();
    cout << endl;
    return 0;
}
