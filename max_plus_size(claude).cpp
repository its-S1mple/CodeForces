#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        if (n == 1) {
            cout << a[0] + 1 << endl;
            continue;
        }

        vector<pair<int, int>> dp(n);  // {max element, count of colored elements}
        
        dp[0] = {a[0], 1};
        dp[1] = {max(a[0], a[1]), 1};

        for (int i = 2; i < n; i++) {
            // Option 1: Don't color the current element
            auto option1 = dp[i-1];
            
            // Option 2: Color the current element
            auto option2 = dp[i-2];
            option2.first = max(option2.first, a[i]);
            option2.second++;

            // Choose the option with higher score
            if (option1.first + option1.second >= option2.first + option2.second) {
                dp[i] = option1;
            } else {
                dp[i] = option2;
            }
        }

        cout << dp[n-1].first + dp[n-1].second << endl;
    }
    return 0;
}