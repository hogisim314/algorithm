#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const int& a, const int& b) {
    return a>b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), cmp);
    bool flag = true;
    for (int i=1000; i>=0; i--) {
        flag = true;
        for (int j=0; j<i; j++) {
            if (citations[j]<i) {
                flag = false;
            }
        }
        if (flag) {
            answer = i;
            break;
        }
    }
    
    return answer;
}