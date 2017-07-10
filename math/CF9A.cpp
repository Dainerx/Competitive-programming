#include <algorithm>
#include <vector>
#include <iostream>
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



int main(){

    short a,b;
    cin >> a >> b;  

    short max_;
    short odds=0;
    
    
    max_ = max(a,b);
    
    for (int i=0; i<=6; i++)
    {
        if (max_<=i)
        odds+=1;
    }
    
    
    double oddsf = (double)odds/6;
    
    double x1=(double)3/6;
    double x2=(double)2/6;
    double x3=(double)4/6;
    double x4=(double)6/6;

    cout.precision(5);
    cout <<"";
    
    if (oddsf==x1)
        cout << 1 << "/" << 2;
    else if (oddsf==x2)
        cout << 1 << "/" << 3;
    else if (oddsf==x3)
        cout << 2 << "/" << 3;
    else if (oddsf==x4)
        cout << 1 << "/" << 1;        
    else if (oddsf==0)
        cout << 0 << "/" << 1;
    else
    cout << odds << "/" << 6;
    

}
