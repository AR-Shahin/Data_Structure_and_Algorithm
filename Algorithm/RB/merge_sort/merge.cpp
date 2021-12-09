#include <bits/stdc++.h>
using namespace std;

int B[100];
void print_array(int A[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void merge_asc(int A[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }

    for (int k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}
void merge_dsc(int A[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (A[i] >= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }

    for (int k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}

void merge_sort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(A, lb, mid);
        merge_sort(A, mid + 1, ub);
        merge_dsc(A, lb, mid, ub);
    }
}

int main()
{
    int A[] = {10, 2, 5, 7, 3, 4};
    int n = 6;
    print_array(A, n);
    merge_sort(A, 0, n - 1);
    print_array(A, n);
    return 0;
}

