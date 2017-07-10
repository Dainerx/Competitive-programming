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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

int main(int argc, char *argv[]) {

    int n;
    map<unsigned long, unsigned long> first_line;
    std::map<unsigned long, unsigned long>::iterator it_first;
    map<unsigned long, unsigned long> second_line;
    std::map<unsigned long, unsigned long>::iterator it_second;
    map<unsigned long, unsigned long> third_line;
    std::map<unsigned long, unsigned long>::iterator it_third;
    cin >>n;

    FOR(i, 0, n) {
        long long a;
        cin >> a;
        if (first_line.find(a) != first_line.end()) {
            it_first = first_line.find(a);
            it_first->second += 1;
        } else {
            first_line.insert(mp(a, 0));
        }
    }

    FOR(i, 0, n - 1) {
        long long b;
        cin >> b;
        if (second_line.find(b) != second_line.end()) {
            it_second = second_line.find(b);
            it_second->second += 1;
        } else {
            second_line.insert(mp(b, 0));
        }
    }

    FOR(i, 0, n - 2) {
        long long c;
        cin >> c;
        if (third_line.find(c) != third_line.end()) {
            it_third = third_line.find(c);
            it_third->second += 1;
        } else {
            third_line.insert(mp(c, 0));
        }
    }

    std::map<unsigned long, unsigned long>::iterator it;
    for (it = first_line.begin(); it != first_line.end(); ++it) {
        if (second_line.find(it->first) != second_line.end()) {
            if (second_line.find(it->first)->second != it->second) {
                break;
            }
        } else {
            break;
        }
    }

    std::map<unsigned long, unsigned long>::iterator it1;
    for (it1 = second_line.begin(); it1 != second_line.end(); ++it1) {
        if (third_line.find(it1->first) != third_line.end()) {
            if (third_line.find(it1->first)->second != it1->second) {
                break;
            }
        } else {
            break;
        }
    }



    cout << it->first << endl << it1->first;

    return 0;
}
