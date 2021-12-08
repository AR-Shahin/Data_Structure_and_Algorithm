#include <bits/stdc++.h>
using namespace std;
int binary_search(int A[], int low, int high, int val)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (A[mid] == val)
        {
            return mid;
        }
        else if (A[mid] > val)
        {
            return binary_search(A, low, mid, val);
        }
        else if (A[mid] < val)
        {
            return binary_search(A, mid + 1, high, val);
        }
    }
    return -1;
}
int main()
{
    int A[] = {-8, -1, 5, 9, 10, 17, 18, 25, 36};
    int n = 9;
    int val = 180;
    int pos = binary_search(A, 0, n - 1, val);
    cout << pos;
    return 0;
}
