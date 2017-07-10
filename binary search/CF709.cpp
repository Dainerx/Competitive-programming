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
#include <ctype.h>
#include <map>
#include <set>
#include <numeric>
#include <bits/stl_bvector.h>

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORJ(j,a,b) for(int j=(a);j<(b);j++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back


int main() {

    signed int n;
    long b=-1,counter=1;
    scanf("%i",&n);
    vector <long> results;
    FOR(i,0,n)
    {
        long int a;
        scanf("%di",&a);
        if (i==0)
        {
            b=a;
            continue;
        }
        if (a>b)
            counter++;
        else
        {
            results.pb(counter);
            counter=1;
        }
        b=a;
    }
    
    results.pb(counter);
    cout << *std::max_element(results.begin(),results.end());
    
    return 0;
}
