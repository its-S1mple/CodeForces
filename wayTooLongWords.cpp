// codefoeces problem no. 71A
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void valid_string(string name)
{
    int n = name.length();
    if (n > 10)
    {
        cout << name[0] << n - 2 << name[n - 1]<<endl;;
    }
    else
    {
        cout << name<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        valid_string(v[i]);
    }

    return 0;
}