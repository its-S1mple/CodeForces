#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<long long> results;

    // Read all inputs and process them
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        int count = 0;

        while (n != 0) {
            if (k > n || k == 1) {
                count += n;
                break;
            } else {
                long long x = 1;
                while (x * k <= n) {
                    x *= k;
                }
                n -= x;
                count++;
            }
        }
        results.push_back(count);
    }

    // Output all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}