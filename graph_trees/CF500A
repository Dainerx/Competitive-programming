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

vector<vector< int > > G;


int main() {

    int n,t;
    cin >> n >> t;
    G.resize(n);
    FOR(i,0,n-1) {
        int a;
        cin>> a;
        G[i].push_back(i+a);
    }
    
    int sd=G[0].at(0);
    while(1) {
        int side=sd+1;
        if (side==t)
        {
            cout << "YES";
            return 0;
        }
        
        if (side>t)
        {
            cout << "NO";
            return 0;
        }
        
        sd=G[sd].at(0);
    }
     
    
    return 0;
}
