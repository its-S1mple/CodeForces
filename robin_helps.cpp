#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    vector<int> result;

    while (tt--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

       
        int gold = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0 && gold != 0)
            {
                gold -= 1;
                count++;
            }
            if (a[i] >= k)
            {
                gold += a[i];
            }
        }
        result.push_back(count);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}

// 4
// 2 2
// 2 0
// 3 2
// 3 0 0
// 6 2
// 0 3 0 0 0 0
// 2 5
// 5 4
