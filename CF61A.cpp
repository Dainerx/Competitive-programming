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

    string s,s1,final="";
    cin>>s>>s1;
    FOR(i,0,s.size())
    {
        final += (short(s[i]) ^ short(s1[i]))+'0';
    }
    cout << final;
    return 0;
}
