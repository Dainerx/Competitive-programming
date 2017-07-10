
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

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   problemA.cpp
 * Author: dainer
 *
 * Created on March 13, 2017, 11:50 AM
 */


int main()
{
    

    const int size = 100010;
    ll x[size], h[size];
    int counter;
    
    int n; 
    cin >> n;
    
    if (n==1)
    {
        counter=1;
        cout << counter;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> h[i];
    }    
    counter=2;
    ll left=x[0];
    
    for (int i = 1; i < n - 1; ++i) {
        if (left < (x[i] - h[i])) {
            ++counter;
            left = x[i];
        } else if ((x[i] + h[i]) < x[i + 1]) {
            ++counter;
            left = x[i] + h[i];
        } else {
            left = x[i];
        }
    }
    
    cout << counter;
    
    return 0;

}
