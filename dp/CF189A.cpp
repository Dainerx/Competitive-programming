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
#define FORJ(j,a,b) for(int j=(a);j<(b);j++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back




vector <int> abc;
int states[4001];

int dp(int ribbon) {

    if (ribbon == 0)
        return 0;
    
    if (ribbon<0)
        return -10000;

    if (states[ribbon] != -1)
        return states[ribbon];
    
    return states[ribbon] = MAX(1 + dp(ribbon - abc[1]), 1 + dp(ribbon - abc[0]), 1 + dp(ribbon - abc[2]));
}

int main() {

    memset(states, -1, sizeof (states));

    int n, a, b, c;
    scanf("%i %i %i %i", &n, &a, &b, &c);
    abc.pb(a);
    abc.pb(b);
    abc.pb(c);
    sort(abc.begin(), abc.end());

    printf("%i", dp(n));

    return 0;
}
