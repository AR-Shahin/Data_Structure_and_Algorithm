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
    // File : 1
    double F1Asc[10];
    double F1Dsc[10];
    ifstream myFile;
    myFile.open("input1.txt");
    // myFile.open("i3.txt");

    int n1;
    myFile >> n1;
    int A[n1];
    // Read File One
    for (int i = 0; i < n1; i++)
    {
        myFile >> A[i];
    }
    myFile.close();

    // Bubble Sort Asc Start
    clock_t bbAscClockStart = clock();
    bubble_sort_asc(A, n1);
    clock_t bbAscClockEnd = clock();
    double bbAscTime = (bbAscClockEnd - bbAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[0] = bbAscTime;
    freopen("i1_bubble_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Bubble Sort Asc End : -----------------------------------------------

    // Bubble Sort Dsc Start
    clock_t bbDscClockStart = clock();
    bubble_sort_dsc(A, n1);
    clock_t bbDscClockEnd = clock();
    double bbDscTime = (bbDscClockEnd - bbDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[0] = bbDscTime;
    freopen("i1_bubble_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Bubble Sort Asc End : -------------------------------------

    // Merge Sort ASC Start
    clock_t mgAscClockStart = clock();
    merge_sort_asc(A, 0, n1 - 1);
    clock_t mgAscClockEnd = clock();
    double mgAscTime = (mgAscClockEnd - mgAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[1] = mgAscTime;
    freopen("i1_merge_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Merge Sort Asc End : -----------------------------------------------

    // Merge Sort DSC Start
    clock_t mgDscClockStart = clock();
    merge_sort_dsc(A, 0, n1 - 1);
    clock_t mgDscClockEnd = clock();
    double mgDscTime = (mgDscClockEnd - mgDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[1] = mgDscTime;
    freopen("i1_merge_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Quick Sort Dsc End : -----------------------------------------------

    // Quick Sort ASC Start
    clock_t qsAscClockStart = clock();
    quick_sort_asc(A, 0, n1 - 1);
    clock_t qsAscClockEnd = clock();
    double qsAscTime = (qsAscClockEnd - qsAscClockStart) / CLOCKS_PER_SEC;
    F1Asc[2] = qsAscTime;
    freopen("i1_quick_asc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Quick Sort Asc End : -----------------------------------------------

    // Quick Sort DSC Start
    clock_t qsDscClockStart = clock();
    quick_sort_dsc(A, 0, n1 - 1);
    clock_t qsDscClockEnd = clock();
    double qsDscTime = (qsDscClockEnd - qsDscClockStart) / CLOCKS_PER_SEC;
    F1Dsc[2] = qsDscTime;
    freopen("i1_quick_dsc.txt", "w", stdout);
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << "\t";
    }

    // ------------------------ Quick Sort Dsc End : -----------------------------------------------
    int x[] = {-7, 8, 10};
    // Final Result :
    freopen("final.txt", "w", stdout);
    cout << "Input 1 :" << endl;
    cout << "Bubble sort : ASC = " << bbAscTime << "S DSC = " << bbDscTime << "S" << endl;
    cout << "Merge sort : ASC = " << mgAscTime << "S DSC = " << mgDscTime << "S" << endl;
    cout << "Quick sort : ASC = " << qsAscTime << "S DSC = " << qsDscTime << "S" << endl;
    cout << "Best Sorting : ASC = " << get_best_result(F1Asc, 3) << " Sort DSC = " << get_best_result(F1Dsc, 3) << " Sort";
    // cout << get_best_result(x, 4);
    return 0;
}
