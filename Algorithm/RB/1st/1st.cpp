#include <bits/stdc++.h>
using namespace std;
void Even(int arr[], int n)
{
    freopen("./assets/out/even.txt", "w", stdout);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << "Even " << arr[i] << endl;
        }
    }
}

void Odd(int arr[], int n)
{
    freopen("./assets/out/odd.txt", "w", stdout);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << "Odd " << arr[i] << endl;
        }
    }
}
int main()
{
    int arr[100];
    int n;
    clock_t t1 = clock();
    // freopen("./assets/in/input.txt", "r", stdin);
    // // freopen("./assets/out/output.txt", "w", stdout);
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // Even(arr, n);
    // Odd(arr, n);
    for (int i = 0; i < 100000; i++)
    {
        cout << "-";
    }
    clock_t t2 = clock();
    double diff = t2 - t1;
    cout << " " << endl;
    cout << diff / CLOCKS_PER_SEC;
    return 0;
}
