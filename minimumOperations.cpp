#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
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
        cout << count << endl;
    }
    return 0;
}