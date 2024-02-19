#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;
set<string> s;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (int i=0; i<phone_book.size(); i++) {
        s.insert(phone_book[i]);
    }
    
    for (int i=0; i<phone_book.size(); i++) {
        for (int j=1; j<=phone_book[i].size()-1; j++) {
            if (s.find(phone_book[i].substr(0,j))!=s.end()) {
                return false;
            }
        }
    }
    
    
    
    return answer;
}