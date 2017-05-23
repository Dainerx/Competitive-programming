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

    
    short n;
    double result,final;
    cin>>n;
    FOR(i,0,n)
    {
        double p;
        cin>>p;
        if (p==0)
            result+=0;
        else
        {
            result+=(2*((p/100)));
        }
    }
    result=result/2;
    final =result/n;
    cout << final*100;
    return 0;
}
