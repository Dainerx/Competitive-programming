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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main(int argc, char *argv[]) {


    int n;
    vector <string> final;
    map<string,int>input;
    std::map<string,int>::iterator it;
    cin>>n;
    FOR(i, 0, n) {
        string request;
        cin>>request;
        if (i == 0) {
            final.pb("OK");
            input.insert(mp(request,0));
        } else {
            it = input.find(request);
            if (it != input.end()) {
                it->second+=1;
                string to_ = std::to_string(it->second);
                final.pb(request+to_);
            } else {
                final.pb("OK");
                input.insert(mp(request,0));
            }
        }

    }

    FOR(i, 0, n) {
        cout << final.at(i) << endl;
    }
    return 0;
}
