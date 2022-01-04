#include <bits/stdc++.h>
using namespace std;
int A[100], n = 0;
void my_swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int parent(int i)
{
    return i / 2;
}
int left(int i)
{
    return 2 * i;
}
int right(int i)
{
    return (2 * i) + 1;
}
void min_heap_insert(int val)
{
    n = n + 1;
    A[n] = val;
    int i = n;
    while (i > 1)
    {
        int p = parent(i);
        if (A[p] > A[i])
        {
            my_swap(&A[p], &A[i]);
            i = p;
        }
        else
        {
            break;
        }
    }
}
void max_heap_insert(int val)
{
    n = n + 1;
    A[n] = val;
    int i = n;
    while (i > 1)
    {
        int p = parent(i);
        if (A[p] < A[i])
        {
            my_swap(&A[p], &A[i]);
            i = p;
        }
        else
        {
            break;
        }
    }
}
void print_heap(int A[], int heap_size)
{
    cout << endl;
    if (n == 0)
    {
        cout << "Empty Heap!!\n";
    }
    for (int i = 1; i <= heap_size; i++)
    {
        cout << A[i] << " ";
    }
}

int delete_max_heap()
{
    if (n == 0)
    {
        return -1;
    }
    int val = A[1];
    int temp = A[n];
    n--;
    int i = 1;
    A[i] = temp;
    while (i < n)
    {
        int l = left(i);
        int r = right(i);
        if (A[i] < A[l])
        {
            my_swap(&A[i], &A[l]);
            i = l;
        }
        else if (A[i] < A[r])
        {
            my_swap(&A[i], &A[l]);
            i = r;
        }
        else
        {
            break;
        }
    }

    return val;
}

int delete_min_heap()
{
    if (n == 0)
    {
        return -1;
    }
    int val = A[1];
    int temp = A[n];
    n--;
    int i = 1;
    A[i] = temp;
    while (i < n)
    {
        int l = left(i);
        int r = right(i);
        if (A[i] > A[l])
        {
            my_swap(&A[i], &A[l]);
            i = l;
        }
        else if (A[i] > A[r])
        {
            my_swap(&A[i], &A[l]);
            i = r;
        }
        else
        {
            break;
        }
    }

    return val;
}
int peek()
{
    if (n == 0)
    {
        return -1111;
    }
    return A[1];
}
int main()
{
    int choice, play;
    cout << "How Many time do you want to Play? : ";
    cin >> play;
    cout << endl;
    cout << "(1) : Insert" << endl;
    cout << "(2) : Display" << endl;
    cout << "(3) : Delete" << endl;
    cout << "(4) : Quit" << endl;
    do
    {
        cout << "\nEnter your Choice : ";
        cin >> choice;
        cout << "--------------------------\n";
        play--;

        switch (choice)
        {
        case 1:
            cout << "Insert Data : ";
            int val;
            cin >> val;
            max_heap_insert(val);
            cout << "You've Inserted : " << val << endl;
            break;
        case 2:
            if (n != 0)
            {
                cout << "Heap Data : ";
            }

            print_heap(A, n);
            break;
        case 3:
            cout << "Deleted Data : " << delete_max_heap() << endl;
            break;
        case 4:
            cout << "Game Over!";
            play = 0;
            break;
        default:
            cout << "Wrong Choice! Choose 1 to 3\n";
            break;
        }

    } while (play != 0);

    // max_heap_insert(1);
    // max_heap_insert(3);
    // max_heap_insert(5);
    // max_heap_insert(4);
    // max_heap_insert(6);
    // print_heap(A, n);
    return 0;
}
