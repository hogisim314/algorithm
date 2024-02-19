#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> m;
int cnt;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i=0; i<participant.size(); i++) {
        if (m.find(participant[i])!=m.end()) {
            cnt = m[participant[i]];
            m[participant[i]]=cnt+1;
        }
        else {
            m.insert({participant[i], 1});
        }
    }
    
    for (int i=0; i<completion.size(); i++) {
        m[completion[i]]--;
    }
    
    for (auto itr = m.begin(); itr!=m.end(); itr++) {
        if (itr->second>0) {
            answer += itr->first;
            break;
        }
    }
    return answer;
}