#include <stdio.h>
int main()
{
    int n, row, col, star, space;
    cin >> n;
    for (row = 1; row <= n; row++)
    {
        space = n - row;
        for (col = 1; col <= space; col++)
        {
            cout << " ";
        }
        star = 2 * row - 1;
        for (col = 1; col <= star; col++)
        {
            if (row == 1 || col == 1 || col == star)
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (row = n - 1; row >= 1; row--)
    {
        space = n - row;
        for (col = 1; col <= space; col++)
        {
            cout << " ";
        }
        star = 2 * row - 1;
        for (col = 1; col <= star; col++)
        {
            if (row == 1 || col == 1 || col == star)
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
}
