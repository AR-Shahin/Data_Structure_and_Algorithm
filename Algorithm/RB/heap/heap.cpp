#include <bits/stdc++.h>
using namespace std;
int A[100], n = 0;
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
            swap(A[p], A[i]);
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
            swap(A[p], A[i]);
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
            swap(A[i], A[l]);
            i = l;
        }
        else if (A[i] < A[r])
        {
            swap(A[i], A[l]);
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
            swap(A[i], A[l]);
            i = l;
        }
        else if (A[i] > A[r])
        {
            swap(A[i], A[l]);
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
    return A[1];
}
int main()
{
    int arr[] = {1,
                 3,
                 5,
                 4,
                 6};
    for (int i = 0; i < 5; i++)
    {
        max_heap_insert(arr[i]);
    }
    print_heap(A, n);
    cout << delete_max_heap();
    print_heap(A, n);
    return 0;
}
