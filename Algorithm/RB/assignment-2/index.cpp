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
    // File : 1
    double F1Asc[10];
    double F1Dsc[10];
    ifstream myFile;
    // myFile.open("input1.txt");
    myFile.open("i1.txt");

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

    // ---- Bubble Sort Asc End : ---

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

    // ----- Bubble Sort Dsc End : -----

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

    // ------- Merge Sort Asc End : --------------

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

    // ------- Quick Sort Dsc End : -----------------

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

    // ------------- Quick Sort Asc End : -----

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

    // ------------- Quick Sort Dsc End : -----------

    // File : 2
    double F2Asc[10];
    double F2Dsc[10];
    ifstream myFile2;
    // myFile.open("input1.txt");
    myFile2.open("i2.txt");

    int n2;
    myFile2 >> n2;
    int C[n2];
    // Read File Two
    for (int i = 0; i < n2; i++)
    {
        myFile2 >> C[i];
    }
    myFile2.close();

    // Bubble Sort Asc Start
    clock_t F2_bbAscClockStart = clock();
    bubble_sort_asc(C, n1);
    clock_t F2_bbAscClockEnd = clock();
    double F2_bbAscTime = (F2_bbAscClockEnd - F2_bbAscClockStart) / CLOCKS_PER_SEC;
    F2Asc[0] = bbAscTime;
    freopen("i2_bubble_asc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // ---- Bubble Sort Asc End : ---

    // Bubble Sort Dsc Start
    clock_t F2_bbDscClockStart = clock();
    bubble_sort_dsc(C, n2);
    clock_t F2_bbDscClockEnd = clock();
    double F2_bbDscTime = (F2_bbDscClockEnd - F2_bbDscClockStart) / CLOCKS_PER_SEC;
    F2Dsc[0] = F2_bbDscTime;
    freopen("i2_bubble_dsc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // ----- Bubble Sort Dsc End : -----

    // Merge Sort ASC Start
    clock_t F2_mgAscClockStart = clock();
    merge_sort_asc(C, 0, n2 - 1);
    clock_t F2_mgAscClockEnd = clock();
    double F2_mgAscTime = (F2_mgAscClockEnd - F2_mgAscClockStart) / CLOCKS_PER_SEC;
    F2Asc[1] = F2_mgAscTime;
    freopen("i2_merge_asc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // ------- Merge Sort Asc End : --------------

    // Merge Sort DSC Start
    clock_t F2_mgDscClockStart = clock();
    merge_sort_dsc(C, 0, n2 - 1);
    clock_t F2_mgDscClockEnd = clock();
    double F2_mgDscTime = (F2_mgDscClockEnd - F2_mgDscClockStart) / CLOCKS_PER_SEC;
    F2Dsc[1] = F2_mgDscTime;
    freopen("i2_merge_dsc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // ------- Quick Sort Dsc End : -----------------

    // Quick Sort ASC Start
    clock_t F2_qsAscClockStart = clock();
    quick_sort_asc(C, 0, n2 - 1);
    clock_t F2_qsAscClockEnd = clock();
    double F2_qsAscTime = (F2_qsAscClockEnd - F2_qsAscClockStart) / CLOCKS_PER_SEC;
    F2Asc[2] = F2_qsAscTime;
    freopen("i2_quick_asc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // ------------- Quick Sort Asc End : -----

    // Quick Sort DSC Start
    clock_t F2_qsDscClockStart = clock();
    quick_sort_dsc(C, 0, n2 - 1);
    clock_t F2_qsDscClockEnd = clock();
    double F2_qsDscTime = (F2_qsDscClockEnd - F2_qsDscClockStart) / CLOCKS_PER_SEC;
    F2Dsc[2] = F2_qsDscTime;
    freopen("i2_quick_dsc.txt", "w", stdout);
    for (int i = 0; i < n2; i++)
    {
        cout << C[i] << "\t";
    }

    // File : 3
    double F3Asc[10];
    double F3Dsc[10];
    ifstream myFile3;
    // myFile.open("input1.txt");
    myFile3.open("i3.txt");

    int n3;
    myFile3 >> n3;
    int D[n3];
    // Read File Two
    for (int i = 0; i < n3; i++)
    {
        myFile3 >> D[i];
    }
    myFile3.close();

    // Bubble Sort Asc Start
    clock_t F3_bbAscClockStart = clock();
    bubble_sort_asc(D, n3);
    clock_t F3_bbAscClockEnd = clock();
    double F3_bbAscTime = (F3_bbAscClockEnd - F3_bbAscClockStart) / CLOCKS_PER_SEC;
    F3Asc[0] = bbAscTime;
    freopen("i3_bubble_asc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ---- Bubble Sort Asc End : ---

    // Bubble Sort Dsc Start
    clock_t F3_bbDscClockStart = clock();
    bubble_sort_dsc(D, n3);
    clock_t F3_bbDscClockEnd = clock();
    double F3_bbDscTime = (F3_bbDscClockEnd - F3_bbDscClockStart) / CLOCKS_PER_SEC;
    F3Dsc[0] = F3_bbDscTime;
    freopen("i3_bubble_dsc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ----- Bubble Sort Dsc End : -----

    // Merge Sort ASC Start
    clock_t F3_mgAscClockStart = clock();
    merge_sort_asc(D, 0, n3 - 1);
    clock_t F3_mgAscClockEnd = clock();
    double F3_mgAscTime = (F3_mgAscClockEnd - F3_mgAscClockStart) / CLOCKS_PER_SEC;
    F3Asc[1] = F3_mgAscTime;
    freopen("i3_merge_asc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ------- Merge Sort Asc End : --------------

    // Merge Sort DSC Start
    clock_t F3_mgDscClockStart = clock();
    merge_sort_dsc(D, 0, n3 - 1);
    clock_t F3_mgDscClockEnd = clock();
    double F3_mgDscTime = (F3_mgDscClockEnd - F3_mgDscClockStart) / CLOCKS_PER_SEC;
    F3Dsc[1] = F3_mgDscTime;
    freopen("i3_merge_dsc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ------- Quick Sort Dsc End : -----------------

    // Quick Sort ASC Start
    clock_t F3_qsAscClockStart = clock();
    quick_sort_asc(D, 0, n3 - 1);
    clock_t F3_qsAscClockEnd = clock();
    double F3_qsAscTime = (F3_qsAscClockEnd - F3_qsAscClockStart) / CLOCKS_PER_SEC;
    F3Asc[2] = F3_qsAscTime;
    freopen("i3_quick_asc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ------------- Quick Sort Asc End : -----

    // Quick Sort DSC Start
    clock_t F3_qsDscClockStart = clock();
    quick_sort_dsc(D, 0, n3 - 1);
    clock_t F3_qsDscClockEnd = clock();
    double F3_qsDscTime = (F3_qsDscClockEnd - F3_qsDscClockStart) / CLOCKS_PER_SEC;
    F3Dsc[2] = F3_qsDscTime;
    freopen("i3_quick_dsc.txt", "w", stdout);
    for (int i = 0; i < n3; i++)
    {
        cout << D[i] << "\t";
    }

    // ------------- Quick Sort Dsc End : -----------

    // int x[] = {-7, 8, 10};
    //  Final Result :

    freopen("final.txt", "w", stdout);
    cout << "Input 1 :" << endl;
    cout << "Bubble sort : ASC = " << bbAscTime << "S DSC = " << bbDscTime << "S" << endl;
    cout << "Merge sort : ASC = " << mgAscTime << "S DSC = " << mgDscTime << "S" << endl;
    cout << "Quick sort : ASC = " << qsAscTime << "S DSC = " << qsDscTime << "S" << endl;
    cout << "Best Sorting : ASC = " << get_best_result(F1Asc, 3) << " Sort DSC = " << get_best_result(F1Dsc, 3) << " Sort";
    cout << endl;
    cout << "\n---------------------" << endl;
    cout << "Input 2 :" << endl;
    cout << "Bubble sort : ASC = " << F2_bbAscTime << "S DSC = " << F2_bbDscTime << "S" << endl;
    cout << "Merge sort : ASC = " << F2_mgAscTime << "S DSC = " << F2_mgDscTime << "S" << endl;
    cout << "Quick sort : ASC = " << F2_qsAscTime << "S DSC = " << F2_qsDscTime << "S" << endl;
    cout << "Best Sorting : ASC = " << get_best_result(F2Asc, 3) << " Sort DSC = " << get_best_result(F2Dsc, 3) << " Sort";
    cout << endl;
    cout << "\n---------------------" << endl;

    cout << "Input 3 :" << endl;
    cout << "Bubble sort : ASC = " << F3_bbAscTime << "S DSC = " << F3_bbDscTime << "S" << endl;
    cout << "Merge sort : ASC = " << F3_mgAscTime << "S DSC = " << F3_mgDscTime << "S" << endl;
    cout << "Quick sort : ASC = " << F3_qsAscTime << "S DSC = " << F3_qsDscTime << "S" << endl;
    cout << "Best Sorting : ASC = " << get_best_result(F3Asc, 3) << " Sort DSC = " << get_best_result(F3Dsc, 3) << " Sort";
    // cout << get_best_result(x, 4);

    return 0;
}
