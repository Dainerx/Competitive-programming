#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> ranks;
    stack<int> ladder;
    ladder.push(scores[0]);
    for(int i=1; i<scores.size(); i++)
        if (scores[i]!=ladder.top())
            ladder.push(scores[i]);
    
    for(int i =  0; i < alice.size(); i++)
    {
        while(ladder.size()>0 && alice[i]>=ladder.top())
            ladder.pop();
        int rank = (ladder.size()==0) ? 1 : ladder.size() +1;
        ranks.push_back(rank); 
    }
    return ranks;
}
