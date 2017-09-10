#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
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

bool vis[20000]; //Mark the node if visited 

int main() {

    memset(vis, false, sizeof (vis));
    int n, m;
    cin >> n >>m;
    queue < std::pair<int, int> > q;
    q.push(mp(n, 0));
    vis[ n ] = true;

    while (!q.empty()) {
        std::pair<int, int> p = q.front();
        q.pop();

        if (p.first == m) {
            cout << p.second;
            return 0;
        }
        if (p.first<2*m && p.first*2 < 10001 && vis[p.first * 2] == false) {
            vis[p.first] = true;
            q.push(mp(p.first * 2, p.second + 1));
        }
        
        if (p.first!=0  && vis[p.first - 1] == false) {
            vis[p.first] = true;
            q.push(mp(p.first - 1, p.second + 1));
        }

    }

    return 0;
}
close
