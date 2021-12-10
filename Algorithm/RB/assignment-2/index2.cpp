#include <bits/stdc++.h>
using namespace std;
int B[10000];

int find_min(double A[], int n)
{
    int min = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
}
int get_index(double A[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == val)
        {
            return i;
        }
    }
    return -1;
}
string get_best_result(double A[], int len)
{
    int min = find_min(A, len);

    int index = get_index(A, len, min);
    string best;
    if (index == 0)
    {
        best = "Bubble";
    }
    else if (index == 1)
    {
        best = "Merge";
    }
    else if (index == 2)
    {
        best = "Quick";
    }
    return best;
}

void bubble_sort_asc(int A[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        k++;
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
                f = 1;
            }
        }
        if (f == 0)
        {
            break;
        }
    }
}
void bubble_sort_dsc(int A[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        k++;
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                f = 1;
            }
        }
        if (f == 0)
        {
            break;
        }
    }
}

void print_array(int A[], int len)
{
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int partition_asc(int arr[], int lb, int ub)
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

int partition_dsc(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    for (int j = left + 1; j <= right; j++)
    {
        if (arr[j] > pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i], arr[left]);

    return i;
}
void quick_sort_asc(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition_asc(arr, lb, ub);
        quick_sort_asc(arr, lb, loc - 1);
        quick_sort_asc(arr, loc + 1, ub);
    }
}

void quick_sort_dsc(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition_dsc(arr, lb, ub);
        quick_sort_dsc(arr, lb, loc - 1);
        quick_sort_dsc(arr, loc + 1, ub);
    }
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

void merge_sort_asc(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort_asc(A, lb, mid);
        merge_sort_asc(A, mid + 1, ub);
        merge_asc(A, lb, mid, ub);
    }
}

void merge_sort_dsc(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort_dsc(A, lb, mid);
        merge_sort_dsc(A, mid + 1, ub);
        merge_dsc(A, lb, mid, ub);
    }
}
int main()
{
    ifstream iFile1;
    iFile1.open("i3.txt");
    int *arr1, *arr1_tmp;
    int n1;

    double t1, t2;
    iFile1 >> n1;

    arr1 = new int[n1];
    arr1_tmp = new int[n1];
    int a[n1];
    for (int i = 0; i < n1; i++)
    {
        iFile1 >> a[i];
        // arr1_tmp[i] = arr1[i];
    }

    bubble_sort_asc(a, n1);
    freopen("output1.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << a[i] << " ";
    }
    // print_array(a, n1);
    return 0;
}
