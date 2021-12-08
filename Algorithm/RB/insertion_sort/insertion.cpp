#include <bits/stdc++.h>
using namespace std;

void print_array(int A[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void selection_sort_asc(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] >= temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }
}
void selection_sort_dsc(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] < temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }
}
int main()
{
    int A[] = {3, 4, 1, 2, 10};
    int n = 5;
    print_array(A, n);
    selection_sort_asc(A, n);
    print_array(A, n);
    return 0;
}
