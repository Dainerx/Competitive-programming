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
    while (scanf("%d", &n) && n) {
        scanf("%d %d", &c1, &n1);
        scanf("%d %d", &c2, &n2);
        
        extendedEuclid(n1, n2);
        bool fail = false;
        
        if (n % d) fail = true;
        
        else {
            
            x *= (n / d);
            y *= (n / d);
            ll a = n2 / d;
            ll b = n1 / d;
            ll lf = (ll) ceil(-x / (double) a), rg = (ll) floor(y / (double) b);

            if (lf > rg) fail = true;
            
            else {
                if (c1 * (x + a * lf) + c2 * (y - b * lf) < c1 * (x + a * rg) + c2 * (y - b * rg))
                    x += a * lf, y -= b * lf;
                else
                    x += a * rg, y -= b * rg;
            }
        }
        
        if (fail) puts("failed");
        else printf("%lld %lld\n", x, y);
    }
}
