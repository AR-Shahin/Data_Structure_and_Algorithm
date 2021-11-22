#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n)
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[lb], arr[end]);

    return end;
}
void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
int main()
{
    int arr[] = {5, 30, 50, 15, 20, 1, 20, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, n);
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);

    return 0;
}
