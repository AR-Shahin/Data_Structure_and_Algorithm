#include <bits/stdc++.h>

using namespace std;

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
string get_best_result(double A[], int n)
{
    int min_value = find_min(A, n);
    int index = get_index(A, n, min_value);

    string best;
    if (index == 0)
    {
        best = "Bubble ";
    }
    else if (index == 1)
    {
        best = "Merge ";
    }
    else if (index == 2)
    {
        best = "Quick ";
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

void merge_asc(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_asc(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r - 1) / 2;
    merge_sort_asc(arr, l, m);
    merge_sort_asc(arr, m + 1, r);
    merge_asc(arr, l, m, r);
}

void merge_dsc(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] > R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_dsc(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r - 1) / 2;
    merge_sort_dsc(arr, l, m);
    merge_sort_dsc(arr, m + 1, r);
    merge_dsc(arr, l, m, r);
}
int main()
{
    double F1Asc[10];
    double F1Dsc[10];
    ifstream myFile1;

    myFile1.open("i1.txt");
    int n1;

    myFile1 >> n1;
    cout << n1;

    int A[n1];

    for (int i = 0; i < n1; i++)
    {
        myFile1 >> A[i];
    }

    myFile1.close();

    // Bubble Sort ASC

    clock_t bbAscClockStart = clock();
    bubble_sort_asc(A, n1);
    clock_t bbAscClockEnd = clock();

    double bbAscTime = (bbAscClockEnd - bbAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[0] = bbAscTime;

    freopen("n1_bubble_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Bubble Sort DSC
    clock_t bbDscClockStart = clock();
    bubble_sort_dsc(A, n1);
    clock_t bbDscClockEnd = clock();

    double bbDscTime = (bbDscClockEnd - bbDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[0] = bbDscTime;

    freopen("n1_bubble_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Merge Sort Asc
    clock_t mgAscClockStart = clock();
    merge_sort_asc(A, 0, n1 - 1);
    clock_t mgAscClockEnd = clock();

    double mgAscTime = (mgAscClockEnd - mgAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[1] = mgAscTime;

    freopen("n1_merge_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Merge Sort Dsc
    clock_t mgDscClockStart = clock();
    merge_sort_dsc(A, 0, n1 - 1);
    clock_t mgDscClockEnd = clock();

    double mgDscTime = (mgDscClockEnd - mgDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[1] = mgAscTime;

    freopen("n1_merge_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Quick Sort Asc
    clock_t qcAscClockStart = clock();
    quick_sort_asc(A, 0, n1 - 1);
    clock_t qcAscClockEnd = clock();

    double qcAscTime = (qcAscClockEnd - qcAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[2] = qcAscTime;

    freopen("n1_quick_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Quick Sort Dsc
    clock_t qcDscClockStart = clock();
    quick_sort_dsc(A, 0, n1 - 1);
    clock_t qcDscClockEnd = clock();

    double qcDscTime = (qcDscClockEnd - qcDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[2] = qcDscTime;

    freopen("n1_quick_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // Final Task

    freopen("nasif_final.txt", "w", stdout);

    cout << "\nInput -1 " << endl;
    cout << "Bubble Sort : ASC = " << bbAscTime << "S DSC = " << bbDscTime << "S" << endl;
    cout << "Merge Sort : ASC = " << mgAscTime << "S DSC = " << mgDscTime << "S" << endl;
    cout << "Quick Sort : ASC = " << qcAscTime << "S DSC = " << qcDscTime << "S" << endl;
    cout << "Best Sorting ASC = " << get_best_result(F1Asc, 3) << "Sort DSC = " << get_best_result(F1Dsc, 3) << " Sort";
    return 0;
}
