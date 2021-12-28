#include <bits/stdc++.h>
using namespace std;

struct item
{
    double w, p, u;
};

bool compare(item a, item b)
{
    return a.u > b.u;
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
int main()
{

    int n, W;
    cin >> n >> W;
    item arr[n];
    cout << "Weight Profit" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].w >> arr[i].p;
        arr[i].u = arr[i].p / arr[i].w;
    }

    /*
        for(int i =0;i<n;i++){
            cout<<arr[i].w <<" "<<arr[i].p<<" " <<arr[i].u<<endl;
        }
        */

    sort(&arr[0], &arr[n], compare);
    // bubble_sort_dsc(arr, n);

    double P = 0;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].u << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (W > arr[i].w)
        {
            P = P + arr[i].p;
            W = W - arr[i].w;
        }
        else
        {
            P = P + W * arr[i].u;
            W = 0;
        }
    }

    cout << "Total Profit = " << P;
    return 0;
}
