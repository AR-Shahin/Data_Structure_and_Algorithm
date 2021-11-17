#include <iostream>
using namespace std;
void display(int A[], int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
void bubble_sort(int A[], int n)
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
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                f = 1;
            }
        }
        if(f == 0){
            break;
        }
    }

    cout<<"k " <<k<<endl;
}
int main()
{
    int A[100], n, i;
    cout << "How many number do you want ? ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << " ] : ";
        cin >> A[i];
    }
    cout << "Before sorted : ";
    display(A, n);
    bubble_sort(A, n);
    cout << "\nAfter sorted ";
    display(A, n);
    return 0;
}
