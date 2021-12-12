#include <bits/stdc++.h>
using namespace std;
#define max_size 5

string names[max_size];
int len = 0;

void insert(string name)
{
    if (len < max_size)
    {
        names[len] = name;
        len++;
    }
    else
    {
        cout << "\nList is full\n";
    }
}

void print_data(string A[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << " ";
    }
}

int search(string name)
{
    for (int i = 0; i < len; i++)
    {
        if (names[i] == name)
        {
            return i;
        }
    }

    return -1;
}

void update(string oldData, string newData)
{
    int index = search(oldData);
    names[index] = newData;
}

void delete_data()
{
    len--;
}

void insert_at(string name, int pos)
{
    if (pos >= max_size)
    {
        cout << "\nInvalid Postion\n";
    }
    else
    {
        names[pos] = name;
    }
}
int main()
{
    insert("Shahin");
    insert("Asik");
    insert("Tanzim");
    insert("Omi");
    insert("Nasif");
    // insert("Tamanna ");
    print_data(names, len);
    // cout << endl;
    // // cout << search("Tanzim");
    // update("Omi", "Tamanna");
    // print_data(names, len);
    // delete_data();
    // print_data(names, len);
    insert_at("Ars", 0);
    print_data(names, len);

    return 0;
}
