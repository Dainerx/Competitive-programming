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


    int n, x;
    vector <int> shops;
    cin>>n;

    FOR(i, 0, n) {
        cin>>x;
        shops.pb(x);
    }

    std::sort(shops.begin(), shops.end());

    int q;
    long long m;
    cin>>q;

    FOR(i, 0, q) {
        cin>>m;
        cout << upper_bound(shops.begin(), shops.end(), m) - shops.begin() << endl;
    }

    return 0;
}
