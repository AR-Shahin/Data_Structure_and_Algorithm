#include <bits/stdc++.h>
using namespace std;
#define size 5

int Stack[size];
int top = 0;

void push(int val)
{
    if (top < size)
    {
        Stack[top] = val;
        top++;
    }
    else
    {
        cout << "\nStack is Full" << endl;
    }
}
void display()
{
    for (int i = top - 1; i >= 0; i--)
    {
        cout << Stack[i] << " ";
    }
}

int pop()
{
    int temp = Stack[top - 1];
    top--;
    return temp;
}

int peek()
{
    int temp = Stack[top - 1];
    return temp;
}

int length_of_stack()
{
    return top;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    cout << endl;
    cout << pop();
    cout << " ";
    cout << pop();
    cout << endl;
    display();
    cout << "\n";
    cout << "Peek " << peek() << endl;
    pop();
    cout << "Length of Stack " << length_of_stack();
    return 0;
}
