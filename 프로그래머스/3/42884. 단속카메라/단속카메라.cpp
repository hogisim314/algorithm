#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<int, int> > OutIn;
int camPos;

bool check_overLap(int camPos) {
    if (OutIn.empty()) {
        return false;
    }
    int In = OutIn.top().second;
    int Out = -OutIn.top().first;
    if (In<=camPos && camPos<=Out) {
        return true;
    }
    
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    for (int i=0; i<routes.size(); i++) {
        OutIn.push({-routes[i][1], routes[i][0]});
    }
    
    while(!OutIn.empty()) {
        camPos = -OutIn.top().first;
        OutIn.pop();
        answer++;
        
        // cout<<camPos<<' '<<OutIn.top().second<<' '<<-OutIn.top().first<<check_overLap(camPos)<<'\n';
        
        while(check_overLap(camPos)) {
            OutIn.pop();
        }
    }
    
    
    
    return answer;
}