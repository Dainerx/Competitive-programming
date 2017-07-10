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



    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5>>k6;

    long long _256 = 0, _32 = 0;

    if (k2 == 0) {
        cout << 0;
        return 0;
    } else {
        while (k6 != 0 && k5 != 0 && k2 != 0) {
            _256++;
            k6--;
            k5--;
            k2--;
        }
        while (k2!=0 && k3!=0) {
            _32++;
            k3--;
            k2--;
        }
        
        cout << (_256*256) + (_32*32);
    }

    return 0;
}
