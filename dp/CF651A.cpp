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




int states[200][200];

int dp(int a1, int a2) {
    
    if (a1 == 0 || a2 == 0)
        return 0;
    
    if (states[a1][a2]!=-1)
        return states[a1][a2];
    
    int res = -1000;
    
    if (a1-2>=0)
        res = max (res,dp(a1 - 2, a2 + 1) + 1);
    if (a2-2>=0)
        res = max (res,dp(a1 + 1, a2 - 2) + 1);
    if (!(a2-2>=0 || a1-2>=0))
        return 0;
    
    return states[a1][a2] = res;
}

int main() {

    memset(states, -1, sizeof (states));

    int a1, a2;
    scanf("%i %i", &a1, &a2);

    printf("%i", dp(a1, a2));

    return 0;
}
