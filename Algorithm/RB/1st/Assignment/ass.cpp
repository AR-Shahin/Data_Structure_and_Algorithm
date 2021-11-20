
#include <bits/stdc++.h>
using namespace std;

int main()
{

    clock_t t1 = clock();

    int HEIGHT, WIDTH = 2; //declaring

    /* Code to read in txt file */
    ifstream myFile;
    myFile.open("test.txt");

    if (!myFile)
    {
        cerr << "Unable to open file\n"
             << endl;
        exit(1); // call system to stop
    }
    /* end code read text file */
    myFile >> HEIGHT;
    //  cout<< HEIGHT;
    int arr[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++)
    {
        myFile >> arr[i][0];
        myFile >> arr[i][1];
    }

    myFile.close();
    /*
    for (int i =0;i<HEIGHT;i++){
        cout<<arr[i][0]<<" " ;
        cout<<arr[i][1]<<" " ;
        cout<<endl;
    }
*/

    for (int i = 0; i < HEIGHT - 1; i++)
    {
        for (int j = 0; j < HEIGHT - i - 1; j++)
        {

            cout << arr[j][0] << " " << arr[j + 1][0] << endl;
            if (arr[j][0] < arr[j + 1][0])
            {
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
            else if (arr[j][0] == arr[j + 1][0])
            {
                if (arr[j][1] < arr[j + 1][1])
                {
                    swap(arr[j][0], arr[j + 1][0]);
                    swap(arr[j][1], arr[j + 1][1]);
                }
            }
        }
    }
    /*
    freopen("output.txt", "w", stdout);
    for (int j = 0; j < HEIGHT; j++)
    {
        cout << arr[j][0] << " " << arr[j][1] << endl;
    }
    clock_t t2 = clock();
    clock_t t = (t2 - t1) / CLOCKS_PER_SEC;
    cout << "total time =" << t << endl;
*/
    return 0;
}
