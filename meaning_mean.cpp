#include <iostream>
#include <vector>
#include <algorithm> ///to include sort
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> results;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        while (a.size() > 1) {
            sort(a.begin(), a.end()); // Sort in ascending order
            
            if (a.size() == 2) {
                // If only two elements left, average them
                int avg = (a[0] + a[1]) / 2;
                 results.push_back(avg); //this is the max avg possiblle
                 break;
            } else {
                // Average 2 smallest numbers
                int avg = (a[0] + a[1]) / 2;
                a.erase(a.begin(),a.begin()+2); // Remove the smallest 2 elemnts
                a.push_back(avg); //add the new element avg to the vector
            }
        }

    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}