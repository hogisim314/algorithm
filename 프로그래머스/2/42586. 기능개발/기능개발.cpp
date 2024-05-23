#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> rest;
    queue<int> q;
    for (int i=0; i<progresses.size(); i++) {
        int num = 100 - progresses[i];
        if (num%speeds[i]==0) {
            q.push(num/speeds[i]);
        }
        else {
            q.push(num/speeds[i]+1);
        }
    }
    
    while(!q.empty()) {
        int top = q.front();
        int cnt = 1;
        q.pop();
        
        while(!q.empty() && top>=q.front()) {
            q.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    return answer;
}