#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <complex>
#include <math.h>
#include <string>
#include <string.h>
#include<ctype.h>
#include <map>
#include <set>

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

unsigned long long
choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main() {


    long long n;
    unsigned long b;
    vector <unsigned long> flowers;

    cin>>n;

    FOR(i, 0, n) {
        cin>>b;
        flowers.pb(b);
    }

    std::sort(flowers.begin(), flowers.end());

    if (flowers.at(0) == flowers.at(n - 1)) {
        cout << 0 << " " << n * (n - 1) / 2;
        return 0;
    }

    unsigned long long _diff = 0;
    unsigned long long _ways = 0, _most = 0, _most_ways = 0, _least = 0, _least_ways = 0;
    _most = flowers.at(n - 1);
    _least = flowers.at(0);
    _diff = flowers.at(n - 1) - flowers.at(0);

    FOR(i, 0, n) {
        if (flowers.at(i) == _least)
            _least_ways++;
        else
            break;
    }

    REV(i, 0, n - 1) {
        if (flowers.at(i) == _most)
            _most_ways++;
        else
            break;
    }

    _ways = _most_ways*_least_ways;
    cout << _diff << " " << _ways;

    


    return 0;
}
