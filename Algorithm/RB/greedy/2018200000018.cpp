#include <bits/stdc++.h>
using namespace std;
int HEIGHT;

struct item
{
    double weight, profit, unit;
};
struct solution
{
    int pos;
    double weight, profit;
};

item temp[100];
solution final[100];

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

int main()
{
    int max_weight;
    ifstream myFile;
    myFile.open("input.txt");
    myFile >> HEIGHT >> max_weight;

    item A[HEIGHT];
    // Read Data from file
    for (int i = 0; i < HEIGHT; i++)
    {
        myFile >> A[i].weight >> A[i].profit;
        A[i].unit = A[i].profit / A[i].weight;
    }
    myFile.close();

    // Copy all value in temp
    for (int i = 0; i < HEIGHT; i++)
    {
        temp[i] = A[i];
    }

    freopen("output.txt", "w", stdout);

    bubble_sort_dsc(A, HEIGHT);

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

    cout << "Profit : " << profit << endl;

    for (int i = 0; i < k; i++)
    {
        cout << "Item - " << final[i].pos << " : " << final[i].weight << " = " << final[i].profit << endl;
    }
    return 0;
}
