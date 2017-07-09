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

unsigned int calc(unsigned int n, unsigned int m) {
    unsigned int counter = 0;

    while (n >= 1 && m >= 2 || n >= 2 && m >= 1) {
        if (n > m) {
            n-= 2;
            m--;
            counter++;
        } else if (m > n) {
            n--;
            m-=2;
            counter++;

        } else {
            n--;
            m -= 2;
            counter++;
        }
    }
    return counter;
}

int main() {

    unsigned int n, m;
    scanf("%i %i", &n, &m);
    cout << calc(n, m);
    return 0;
}
