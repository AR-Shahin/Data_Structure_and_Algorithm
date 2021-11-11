#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vac{100, 200, 300};
    vector<int> roll{10000, 20000, 300};
    vector<string> names{"Shahin", "omi", "Asik"};
    vector<int>::iterator it;
    vector<string>::iterator n;
    // vac.insert(0, 500);
    vac.push_back(10);
    vac.push_back(20);
    vac.push_back(30);
    vac.push_back(40);

    //cout << vac.size();
    vac.pop_back();
    // for (int i = 0; i < vac.size(); i++)
    // {
    //     cout << vac[i] << " ";
    // }

    cout << names.back();

    // for (it = vac.begin(); it != vac.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // for (it = roll.begin(); it != roll.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    // for (n = names.begin(); n != names.end(); n++)
    // {
    //     cout << *n << endl;
    // }
    return 0;
}
