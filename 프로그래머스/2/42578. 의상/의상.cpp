#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string name, kind;
map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for (int i=0; i<clothes.size(); i++) {
        name = clothes[i][0];
        kind = clothes[i][1];
        m[kind] ++ ;
    }
    
    for (auto itr = m.begin(); itr!=m.end(); itr++) {
        answer *=(itr->second+1);
    }
    answer-=1;
    
    return answer;
}