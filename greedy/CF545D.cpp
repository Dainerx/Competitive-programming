#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    long long i, n, x = 0, y = 0;
    vector <long> t;
    cin>>n;
    t.resize(n);
    for (i = 0; i < n; i++) {
        long a;
        cin >> a;
        t[i] = a;
    }

    std::stable_sort(t.begin(), t.end());

    for (i = 0; i < n; i++) {
        if (t[i] >= x) {
            x += t[i];
            y++;
        }

    }
    cout << y;
    return 0;
}
