#include <bits/stdc++.h>
using namespace std;
#define WIDTH 2
int HEIGHT;
struct item
{
    double weight, profit, unit;
};
item temp[100];

int position(item val)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        if (temp[i].weight == val.weight && temp[i].profit == val.profit && temp[i].unit == val.unit)
        {
            return i + 1;
        }
    }
    return -1;
}
void bubble_sort_dsc(item A[], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (A[i].unit < A[j].unit)
            {

                item temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
bool compare(item a, item b)
{
    return a.unit > b.unit;
}
struct solution
{
    int pos;
    double weight, profit;
};
solution final[100];
int main()
{
    int max_weight;
    ifstream myFile;
    myFile.open("input.txt");
    myFile >> HEIGHT >> max_weight;

    item A[HEIGHT];
    for (int i = 0; i < HEIGHT; i++)
    {
        myFile >> A[i].weight >> A[i].profit;
        A[i].unit = A[i].profit / A[i].weight;
    }
    myFile.close();

    for (int i = 0; i < HEIGHT; i++)
    {
        temp[i] = A[i];
    }

    freopen("output.txt", "w", stdout);
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << A[i].weight << " ";
        cout << A[i].profit << " ";
        cout << A[i].unit << "\n";
    }
    cout << "-------Before Sorting--------" << endl;
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "W :" << A[i].weight << " P:" << A[i].profit << " U:" << A[i].unit << "\n";
    }
    bubble_sort_dsc(A, HEIGHT);
    // sort(&A[0], &A[HEIGHT], compare);
    int profit = 0;
    int k = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        if (max_weight > A[i].weight)
        {
            max_weight = max_weight - A[i].weight;
            profit = profit + A[i].profit;
            if (max_weight != 0)
            {
                final[k].pos = position(A[i]);
                final[k].weight = A[i].weight;
                final[k].profit = A[i].weight * A[i].unit;
                k++;
            }
        }
        else
        {
            if (max_weight != 0)
            {
                final[k].pos = position(A[i]);
                final[k].weight = A[i].weight - max_weight;
                final[k].profit = max_weight * A[i].unit;
                k++;
            }
            profit = profit + (max_weight * A[i].unit);
            max_weight = 0;
        }
    }
    cout << "-------After Sorting--------" << endl;
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "W :" << A[i].weight << " P:" << A[i].profit << " U:" << A[i].unit << "\n";
    }
    cout << "---------------" << endl;
    cout << profit;
    cout << "\n---------------" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "Item " << final[i].pos << " : W->" << final[i].weight << " P->" << final[i].profit << endl;
    }
    return 0;
}
