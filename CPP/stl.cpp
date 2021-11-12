#include <bits/stdc++.h>
using namespace std;
bool compare_function(string &s1, string &s2)
{
    return (s1.length() > s2.length());
}
int main()
{
    vector<int> vac{100, 200, 300};
    vector<int>::iterator it;

    // it = vac.begin();
    // vac.insert(it, 3, 500);
    // vac.pop_back();
    // for (int i = 0; i < vac.size(); i++)
    // {
    //     cout << vac[i] << " ";
    // }

    list<string> names{"Shahin", "cat", "Omi", "dog", "Badol", "Ars", "cili"};
    list<string>::iterator n = names.begin();

    // names.insert(n, 2, "Shakil");

    names.sort(compare_function);
    for (n = names.begin(); n != names.end(); n++)
    {
        cout << *n << " ";
    }
    return 0;
}
