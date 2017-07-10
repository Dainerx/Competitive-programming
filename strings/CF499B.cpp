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

using namespace std;
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main() {


    short n, m;
    cin >> n>>m;

    map < string, pair< pair<string, string>, pair<int, int> > > languages;
    map < string, pair< pair<string, string>, pair<int, int> > >::iterator it;

    string s1, s2, c;

    FOR(i, 0, m) {
        map <string, int> words;
        cin >> s1>>s2;

        languages.insert(mp(s1, mp(mp(s1, s2), mp(s1.size(), s2.size()))));
    }

    FOR(i, 0, n) {
        cin>>c;
        int _min = min(languages.find(c)->second.second.first, languages.find(c)->second.second.second);

        if (i != n - 1) {
            if (_min == languages.find(c)->second.second.first)
                cout << languages.find(c)->second.first.first << " ";
            else
                cout << languages.find(c)->second.first.second << " ";
        } else {
            if (_min == languages.find(c)->second.second.first)
                cout << languages.find(c)->second.first.first;
            else
                cout << languages.find(c)->second.first.second;
        }

    }
    return 0;

}
