#include <bits/stdc++.h>
using namespace std;
struct item
{
    double w, p, u;
};
bool compare(item A, item B)
{
    return A.u > B.u;
}
void bubble_sort_dsc(item A[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        k++;
        for (int j = i + 1; j < n; j++)
        {
            if (A[i].u < A[j].u)
            {

                double temp = A[i].u;
                A[i].u = A[j].u;
                A[j].u = temp;

                f = 1;
            }
        }
        if (f == 0)
        {
            break;
        }
    }
}

struct valid
{
    int value, items, unit;
};

int main()
{
    int n, W;
    ifstream myFile;
    item arr[200];
    valid brr[200];
    myFile.open("input.txt");
    myFile >> n >> W;

    for (int i = 0; i < n; i++)
    {
        myFile >> arr[i].w >> arr[i].p;
        arr[i].u = arr[i].p / arr[i].w;
    }
    myFile.close();

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].u << " ";
    // }
    bubble_sort_dsc(arr, n);
    // sort(&arr[0], &arr[n], compare);
    int P = 0;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].u << " ";
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (W > arr[i].w)
        {
            brr[k].items = i + 1;
            brr[k].value = arr[i].w;
            brr[k].unit = arr[i].u;
            k++;
            P = P + arr[i].p;
            W = W - arr[i].w;
        }
        else
        {
            P = P + W * arr[i].u;
            W = 0;
            brr[k].items = i + 1;
            brr[k].value = arr[i].w;
            brr[k].unit = arr[i].u;

            k++;
        }
    }
    freopen("output.txt", "w", stdout);
    cout << "Total Profit: " << P << endl;
    // for (int i = 0; i < k; i++)
    // {
    //     cout << "Item - (" << brr[i].unit << ") " << brr[i].items << ":" << brr[i].value << endl;
    // }
}
