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

int main() {

    int n, m;
    vector <unsigned int> worms;

    unsigned int a, q;

    cin>>n;

    FOR(i, 0, n) {
        cin>>a;
        if (i == 0)
            worms.pb(a);
        else
            worms.pb(a + worms.at(i - 1));
    }

    cin >> m;

    FOR(i, 0, m) {
        cin>>q;

        //-worms.begin() gives the exact index differences between two itterators that point to memory

        // lower bound first value that _val<=
        int ans = lower_bound(worms.begin(), worms.end(), q) - worms.begin();
        // upper bound first value that _val>
        /*int ans = upper_bound(worms.begin(),worms.end(),q) - worms.begin();*/

        ans += 1;
        cout << ans << endl;
    }
    return 0;
}
