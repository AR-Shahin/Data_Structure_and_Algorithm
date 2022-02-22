#include <bits/stdc++.h>
using namespace std;
void mergeTwoArray(int A[], int B[], int m, int n, int C[])
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
}
int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    int C[10];
    mergeTwoArray(A, B, 5, 5, C);
    // cout << C[0];
    for (int i = 0; i < 10; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}
