#include <iostream>
using namespace std;

struct activity
{
    int start, end;
    string task;
};
void bubble_sort_asc(activity A[], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (A[i].end > A[j].end)
            {

                activity temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
void optimal_solution(activity A[], int n)
{
    cout << A[0].task << " ";
    activity temp = A[0];
    for (int i = 1; i < n; i++)
    {

        if (temp.end <= A[i].start)
        {
            temp = A[i];
            cout << A[i].task << " ";
        }
    }
}
activity A[10] = {
    {0, 6, "A"},
    {1, 2, "B"},
    {5, 7, "C"},
    {8, 9, "D"},
    {3, 4, "E"},
    {5, 9, "F"},
};
int n = 6;
int main()
{
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << A[i].task << " " << A[i].start << " " << A[i].end << endl;
    // }
    bubble_sort_asc(A, n);
    // cout << "-----------\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << A[i].task << " " << A[i].start << " " << A[i].end << endl;
    // }
    optimal_solution(A, n);
}
