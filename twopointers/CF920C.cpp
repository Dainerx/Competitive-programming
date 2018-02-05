#include <iostream>
#include <math.h>
#include <valarray>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int main() {


    int n; 
    vector <int> ai;
    vector <int> sorted_ai;
    string bytes; 
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a; 
        cin >> a;
        ai.push_back(a);
        sorted_ai.push_back(a);
    }
    
    cin >> bytes;    
    bytes+="0";
    std::sort(sorted_ai.begin(), sorted_ai.end());
    
    int j=0,j_temp = 0;
    
    

    
    while (j<bytes.length())
    {
        if (bytes.at(j)=='0')
        {
            int j_=j;
            j_++;
            std::sort(ai.begin()+j_temp, ai.begin()+j_);
            j_temp=j;
            j_temp++;
        }
        j++;
    }
    
    int i=0;
        
    while (i<n)
    {
        if (ai[i]!=sorted_ai[i])
        {
            cout << "NO";
            return 0;
        }
        i++;
    }
    cout << "YES";
    return 0;
}
