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

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main(int argc, char *argv[]) {

    int n;
    long long x;
    int counter = 0;
    cin >>n>>x;

    FOR(i, 1, n + 1) {
        if ((x % i == 0) && (x/i <= n))
            counter++;
    }

    cout<<counter;

    return 0;
}
