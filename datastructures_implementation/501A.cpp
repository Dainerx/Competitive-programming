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
#define FOR( i, a, b) for(int i = a; i < b; i++)
using namespace std;

/*
 * 
 */
//std::vector<std::string> split(string a) {
//    std::vector<std::string> result;
//    std::istringstream iss(a);
//    for (std::string s; iss >> a;)
//        result.push_back(a);
//    return result;
//}

int dp(int remaining, int a, int b, int c, int depth) {
    if (remaining < 0) {
        return depth;
    }

    int mx = max(dp(remaining - a, a, b, c, depth + 1), depth);
    mx = max(dp(remaining - b, a, b, c, depth + 1), depth);
    mx = max(dp(remaining - c, a, b, c, depth + 1), depth);
    return mx;

}

int main() {

    //int n, a, b, c;
    
    int a, b, c, d;
    int misha[2];
    int vasya[2];
    int points[2];
    
    
    cin >> a; 
    misha[0]=a;
    cin >> b;
    vasya[0]=b;
    
    cin >> c; 
    misha[1]=c;
    cin >> d;
    vasya[1]=d;
    
    
    
    points[0]= max ((3*misha[0]/10),misha[0]-(misha[0]*misha[1]/250));
    points[1]= max ((3*vasya[0]/10),vasya[0]-(vasya[0]*vasya[1]/250));
    
    
    if (points[0]>points[1])
        cout << "Misha";
    else if (points[0]<points[1])
        cout << "Vasya";
    else
        cout << "Tie";

    return 0;
}
