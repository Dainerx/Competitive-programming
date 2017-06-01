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
#include <numeric>

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

bool pairCompare(std::pair<long long, long long> firstElem, std::pair<long long, long long> secondElem) {
    return firstElem.second < secondElem.second;
}

int main() {

    long long n;
    vector <long long> kong;
    cin>>n;
    long long s;

    FOR(i, 0, n) {
        cin>>s;
        kong.pb(s);
    }

    std::sort(kong.begin(), kong.end());

    long long begin = n / 2;
    long long end = n / 2;

    FOR(i, 0, end) {

        for (;;) {
            if (kong[i]*2 <= kong[begin]) {
                n--;
                begin++;
                break;
            } else {
                begin++;
            }
            if (begin == end*2)
                break;
        }
        if (begin == end*2)
            break;
    }

    cout << n;
}
