#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (auto &it : v)
        {
            cin >> it;
        }
        int sum1 = 0, m1 = 0, m2 = 0;
        for (int i = 0; i < v.size(); i += 2)
        {
            sum1++;
            m1 = max(v[i], m1);
        }
        int sum2 = 0;
        for (int i = 1; i < v.size(); i += 2)
        {
            sum2++;
            m2 = max(v[i], m2);
        }

        // cout<<max(sum1+m1,sum2+m2)<<endl;
        int val = max(sum1 + m1, sum2 + m2);
        ans.push_back(val);
    }

    for(auto &it:ans){
        cout<<it<<endl;
    }

    return 0;
}
// 4
// 3
// 5 4 5
// 3
// 4 5 4
// 10
// 3 3 3 3 4 1 2 3 4 5
// 9
// 17 89 92 42 29 92 14 70 45
