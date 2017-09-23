#include <algorithm>
#include <vector>
#include <iostream>
#include <bitset>
#include <fstream>
#include <string> 
#include <stdio.h>
#include <cmath>
#include <complex>
#include <math.h>
#include <limits>
#include <string> 
#include <string.h>
#include<ctype.h>
#include <map>
using namespace std;


#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define SZ(v) (int)v.size()
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define iter(it,s) for(__typeof(s.begin())it = s.begin();it!=s.end();it++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
//typedef map<string, list<string>>::const_iterator MapIterator;

ll x, y, d;

int gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void extendedEuclid(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {

    int n, c1, c2, n1, n2;
    while (cin >> n && n) {
        cin >> c1 >> n1;
        cin >> c2 >> n2;

        extendedEuclid(n1, n2);
        bool failed = false;
        
        if (n % d) 
            failed = true;
        else {
            x *= (n / d);
            y *= (n / d);
            ll aDivider = n2 / d;
            ll bDivider = n1 / d;
            ll lowerBound = (ll) ceil(-x / (double) aDivider);
            ll upperBound = (ll) floor(y / (double) bDivider);

            if (lowerBound > upperBound) failed = true;

            else {
                if (c1 * (x + aDivider * lowerBound) + c2 * (y - bDivider * lowerBound) < c1 * (x + aDivider * upperBound) + c2 * (y - bDivider * upperBound))
                    x += aDivider * lowerBound, y -= bDivider * lowerBound;
                else
                    x += aDivider * upperBound, y -= bDivider * upperBound;
            }
        }

        if (failed) puts("failed");
        else printf("%lld %lld\n", x, y);
    }
}
